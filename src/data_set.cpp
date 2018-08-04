//
// Created by Nidhal DOGGA on 04/08/2018.
//

#include "data_set.h"

void mlkit::data::data_set::set(const mlkit::data::cell &cell, size_t row, size_t col)
{
  assert(col < __vectors.size());
  size_t nrows = __vectors.at(col).cells().size();
  assert(row <= nrows);
  if (row == __vectors.at(col).cells().size()) // Must resize
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

std::vector<mlkit::data::cell>& mlkit::data::data_set::operator[] (const std::string &label)
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




