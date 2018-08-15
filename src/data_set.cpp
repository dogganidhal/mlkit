//
//  data_set.cpp
//  mlkit
//
//  Created by Nidhal DOGGA on 05/08/2018.
//  Copyright © 2018 Nidhal DOGGA. All rights reserved.
//

#include "data_set.h"

void mlkit::data::data_set::set(const mlkit::data::cell &cell, size_t row, size_t col)
{
  assert(col < __vectors.size());
  size_t nrows = __vectors.at(col).cells().size();
  assert(row <= nrows);
  if (row == nrows) // Must resize
    __vectors[col].cells().resize(nrows + 1, cell);
  else
    __vectors[col].cells()[row] = cell;
}

size_t mlkit::data::data_set::ncols()
{
  return __vectors.size();
}

size_t mlkit::data::data_set::nrows()
{
  return __vectors.size() != 0 ? __vectors[0].cells().size() : 0;
}

std::vector<std::string> mlkit::data::data_set::labels()
{
  std::vector<std::string> labels;
  for (size_t col = 0; col < __vectors.size(); col++)
    labels.push_back(__vectors[col].label());
  return labels;
}

mlkit::data::cell mlkit::data::data_set::at(size_t row, size_t col)
{
  assert(col < __vectors.size());
  assert(row < __vectors.at(col).cells().size());
  return __vectors[col].cells()[row];
}

void mlkit::data::data_set::add_col(const std::string &label)
{

  mlkit::data::label_vector new_col(label);
  __vectors.push_back(new_col);

}

mlkit::data::vect& mlkit::data::data_set::operator[] (const std::string &label)
{
  
  for (size_t index = 0; index < __vectors.size(); index++)
  {
    if (__vectors[index].label() == label)
      return __vectors[index].cells();
  }
  
  std::string error_msg = "No column with the name: ";
  error_msg.append(label);
  
  throw std::invalid_argument(error_msg);
  
}

std::tuple<mlkit::data::data_set, mlkit::data::data_set> mlkit::data::data_set::train_test_split(double train_on_test_factor)
{
  
  assert(train_on_test_factor > 0 && train_on_test_factor < 1);
  
  mlkit::data::data_set train_set;
  mlkit::data::data_set test_set;
  std::vector<size_t> indexes;
  size_t train_count = (size_t)((double)nrows() * train_on_test_factor), index = 0;
  
  for (index = 0; index < nrows(); index++)
    indexes.push_back(index);
  
  std::random_shuffle(indexes.begin(), indexes.end());
  
  for (size_t col = 0; col < ncols(); col++)
  {
    index = 0;
    train_set.add_col(__vectors.at(col).label());
    test_set.add_col(__vectors.at(col).label());
    
    for (std::vector<size_t>::iterator iterator = indexes.begin(); iterator != indexes.end(); iterator++)
    {
      if (index < train_count)
        train_set.set(at(*iterator, col), index, col);
      else
        test_set.set(at(*iterator, col), index - train_count, col);
      index++;
    }
  }
  
  return std::tuple<mlkit::data::data_set, mlkit::data::data_set>(train_set, test_set);
}

mlkit::data::vect mlkit::data::data_set::drop_column(size_t index)
{
  mlkit::data::vect col;
  for (size_t row = 0; row < __vectors[index].cells().size(); row++)
    col.push_back(__vectors[index].cells()[row]);
  __vectors.erase(__vectors.begin() + index);
  return col;
}

