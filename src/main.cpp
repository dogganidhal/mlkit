//
//  main.cpp
//  mlkit
//
//  Created by Nidhal DOGGA on 05/08/2018.
//  Copyright © 2018 Nidhal DOGGA. All rights reserved.
//

#include <iostream>
#include "mlkit.h"

int main()
{

  mlkit::data::data_set ds = mlkit::io::csv_reader::read("simple-linear-regression-example.csv");
  auto sets = ds.train_test_split(2.0 / 3.0);
  mlkit::data::data_set train_set = std::get<0>(sets), test_set = std::get<1>(sets);
  
  mlkit::simple_linear_regressor regressor;
  
  mlkit::data::vect train_dependent_var = train_set.drop_column(1);
  mlkit::data::vect test_dependent_var = test_set.drop_column(1);

  regressor.fit(train_set, train_dependent_var);
  
  mlkit::data::vect predicted = regressor.predict(test_set);
  
  for (size_t index = 0; index < predicted.size(); index++)
    std::cout << "Predicted: " << predicted[index] << ", Actual: "
    << test_dependent_var[index] << ", precision: "
    << ((double)(min(test_dependent_var[index], predicted[index])) / (double)(max(test_dependent_var[index], predicted[index])) * 100.0)
    << "%"
    << std::endl;
  
}
