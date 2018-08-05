//
//  cell.h
//  mlkit
//
//  Created by Nidhal DOGGA on 05/08/2018.
//  Copyright © 2018 Nidhal DOGGA. All rights reserved.
//

#ifndef MLKIT_CELL_H
#define MLKIT_CELL_H

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include "macros.h"

MLKIT_NAMESPACE_DEFINE
MLKIT_DATA_NAMESPACE_DEFINE

class cell
{

private:

  std::string __buf;

public:

  cell(const std::string &string);
  cell(const char *buf);
  cell(): cell("") {}
  cell(int val): cell(std::to_string(val)) {}
  cell(double val): cell(std::to_string(val)) {}
  cell(float val): cell(std::to_string(val)) {}

  bool empty();

  operator int();
  operator float();
  operator double();
  operator std::string();
  operator const char *();
  bool operator >(mlkit::data::cell other);
  bool operator <(mlkit::data::cell other);

  friend std::ostream& operator<<(std::ostream& os, const mlkit::data::cell& cell);

};

MLKIT_DATA_NAMESPACE_CLOSE
MLKIT_NAMESPACE_CLOSE

#endif //MLKIT_CELL_H
