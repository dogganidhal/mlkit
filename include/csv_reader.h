//
// Created by Nidhal DOGGA on 04/08/2018.
//

#ifndef MLKIT_CSV_READER_H
#define MLKIT_CSV_READER_H

#include <fstream>
#include <string>
#include "io.h"
#include "data.h"

MLKIT_NAMESPACE_DEFINE
MLKIT_IO_NAMESPACE_DEFINE

class csv_reader
{
  
private:

public:

  static mlkit::data::data_set read(const std::string &path, char delimiter = ',');

};

MLKIT_IO_NAMESPACE_CLOSE
MLKIT_NAMESPACE_CLOSE

#endif //MLKIT_CSV_READER_H
