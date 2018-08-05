//
//  simple_linear_regressor.h
//  mlkit
//
//  Created by Nidhal DOGGA on 05/08/2018.
//  Copyright © 2018 Nidhal DOGGA. All rights reserved.
//

#ifndef simple_linear_regressor_h
#define simple_linear_regressor_h

#include <iostream>
#include "macros.h"
#include "data.h"

#define max(A, B) (A) > (B) ? (A) : (B)
#define min(A, B) (A) < (B) ? (A) : (B)

MLKIT_NAMESPACE_DEFINE

class simple_linear_regressor
{
  
private:
  
  bool __did_fit = false;
  
  double __a = 0.0;
  double __b = 0.0;
  
  double __mean(std::vector<mlkit::data::cell> vect);
  double __variance(std::vector<mlkit::data::cell> vect, double mean);
  double __covariance(std::vector<mlkit::data::cell> vectX, double meanX, std::vector<mlkit::data::cell> vectY, double meanY);
  void __compute_coefficients(std::vector<mlkit::data::cell> vectX, std::vector<mlkit::data::cell> vectY, double &a, double &b);
  
public:
  
  simple_linear_regressor() = default;
  
  void fit(mlkit::data::data_set data_set, std::vector<mlkit::data::cell> dependent_var);
  std::vector<mlkit::data::cell> predict(mlkit::data::data_set ds);
  
};

MLKIT_NAMESPACE_CLOSE

#endif /* simple_linear_regressor_h */
