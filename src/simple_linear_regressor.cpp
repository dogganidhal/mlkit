//
//  simple_linear_regressor.cpp
//  mlkit
//
//  Created by Nidhal DOGGA on 05/08/2018.
//  Copyright © 2018 Nidhal DOGGA. All rights reserved.
//

#include "simple_linear_regressor.h"

double mlkit::simple_linear_regressor::__mean(std::vector<mlkit::data::cell> vect)
{
  double acc = 0.0;
  for (unsigned long index = 0; index < vect.size(); index++)
    acc += (double)vect.at(index);
  return acc / vect.size();
}

double mlkit::simple_linear_regressor::__variance(std::vector<mlkit::data::cell> vect, double mean)
{
  double variance = 0.0;
  for (unsigned long index = 0; index < vect.size(); index++)
  {
    double x = vect.at(index);
    variance += (x - mean) * (x - mean);
  }
  return variance;
}

double mlkit::simple_linear_regressor::__covariance(std::vector<mlkit::data::cell> vectX, double meanX, std::vector<mlkit::data::cell> vectY, double meanY)
{
  double covariance = 0.0;
  for (unsigned long index = 0; index < vectX.size(); index++)
    covariance += ((double)vectX.at(index) - meanX) * ((double)vectY.at(index) - meanY);
  return covariance;
}

void mlkit::simple_linear_regressor::__compute_coefficients(std::vector<mlkit::data::cell> vectX, std::vector<mlkit::data::cell> vectY, double &a, double &b)
{
  double meanX = __mean(vectX);
  double meanY = __mean(vectY);
  a = __covariance(vectX, meanX, vectY, meanY) / __variance(vectX, meanX);
  b = meanY - a * meanX;
}

void mlkit::simple_linear_regressor::fit(mlkit::data::data_set data_set, std::vector<mlkit::data::cell> dependent_var)
{
  assert(data_set.ncols() == 1);
  
  std::string label = data_set.labels()[0];
  std::vector<mlkit::data::cell> vectX = data_set[label];
  
  __compute_coefficients(vectX, dependent_var, __a, __b);
  __did_fit = true;
  
}

std::vector<mlkit::data::cell> mlkit::simple_linear_regressor::predict(mlkit::data::data_set ds)
{
  assert(__did_fit);
  assert(ds.ncols() == 1);
  
  std::string label = ds.labels()[0];
  std::vector<mlkit::data::cell> vectX = ds[label];
  std::vector<mlkit::data::cell> predictions;
  
  for (size_t index = 0; index < vectX.size(); index++)
    predictions.push_back((double)vectX.at(index) * __a + __b);
  
  return predictions;
}






