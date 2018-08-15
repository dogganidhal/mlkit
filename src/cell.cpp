//
//  cell.cpp
//  mlkit
//
//  Created by Nidhal DOGGA on 05/08/2018.
//  Copyright © 2018 Nidhal DOGGA. All rights reserved.
//

#include "../include/cell.h"

mlkit::data::cell::cell(const std::string &string)
{
  __buf = string;
}

mlkit::data::cell::operator float()
{
  float float_value = 0.0;
  std::istringstream(__buf) >> float_value;
  return float_value;
}

mlkit::data::cell::operator int()
{
  int int_value = 0;
  std::istringstream(__buf) >> int_value;
  return int_value;
}

mlkit::data::cell::operator double()
{
  double dbl_value = 0.0;
  std::istringstream(__buf) >> dbl_value;
  return dbl_value;
}

mlkit::data::cell::operator std::string()
{
  std::string str_value;
  std::istringstream(__buf) >> str_value;
  return str_value;
}

mlkit::data::cell::operator const char *()
{
  return __buf.c_str();
}

std::ostream &mlkit::data::operator<<(std::ostream &os, const mlkit::data::cell &cell)
{
  os << cell.__buf;
  return os;
}

mlkit::data::cell::cell(const char *buf)
{
  __buf = std::string(buf);
}

bool mlkit::data::cell::empty()
{
  return __buf.npos > 0;
}

bool mlkit::data::cell::operator >(mlkit::data::cell other)
{
  double lhs = *this;
  double rhs = other;
  return lhs > rhs;
}

bool mlkit::data::cell::operator <(mlkit::data::cell other)
{
  double lhs = *this;
  double rhs = other;
  return lhs < rhs;
}

bool mlkit::data::cell::operator ==(mlkit::data::cell other)
{
  return this->__buf == other.__buf;
}

bool mlkit::data::cell::operator !=(mlkit::data::cell other)
{
  return this->__buf != other.__buf;
}

bool mlkit::data::cell::operator ==(int other)
{
  return ((int)(*this)) == other;
}

bool mlkit::data::cell::operator !=(int other)
{
  return ((int)(*this)) != other;
}

bool mlkit::data::cell::operator ==(std::string other)
{
  return this->__buf == other;
}

bool mlkit::data::cell::operator !=(std::string other)
{
  return this->__buf != other;
}

bool mlkit::data::cell::operator ==(const char *other)
{
  return this->__buf == std::string(other);
}

bool mlkit::data::cell::operator !=(const char *other)
{
  return this->__buf != std::string(other);
}
