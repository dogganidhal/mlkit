//
// Created by Nidhal DOGGA on 04/08/2018.
//

#include "csv_reader.h"

mlkit::data::data_set mlkit::io::csv_reader::read(const char *path)
{
  mlkit::data::data_set data_set;
  std::ifstream fstream;
  std::string line;

  fstream.open(path);
  
  std::string record;
  std::getline(fstream, line);
  std::istringstream sstream(line);
  
  while (std::getline(sstream, record, ','))
    data_set.add_col(record);
  
  size_t row = 0, col = 0;
  
  while (fstream.good())
  {
    col = 0;
    std::getline(fstream, line);
    sstream = std::istringstream(line);
    
    while (std::getline(sstream, record, ','))
    {
      data_set.set(record, row, col);
      col++;
    }
    
    row++;
    
  }

  return data_set;
}

mlkit::data::data_set mlkit::io::csv_reader::read(const std::string &path) {
  return mlkit::io::csv_reader::read(path.c_str());
}
