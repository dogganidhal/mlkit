//
// Created by Nidhal DOGGA on 04/08/2018.
//

#include "csv_reader.h"

mlkit::data::data_set mlkit::io::csv_reader::read(const std::string &path, char delimiter)
{
  try
  {
    mlkit::data::data_set data_set;
    std::ifstream fstream;
    std::string line;
    
    fstream.open(path);
    
    std::string record;
    std::getline(fstream, line);
    std::istringstream sstream(line);
    
    while (std::getline(sstream, record, delimiter))
      data_set.add_col(record);
    
    size_t row = 0, col = 0;
    
    while (fstream.good())
    {
      col = 0;
      std::getline(fstream, line);
      sstream = std::istringstream(line);
      
      while (std::getline(sstream, record, delimiter))
      {
        if (record[0] == '"') // In case there is a comma inside of a double quote fitted string
        {
          
          if (record[record.size() - 1] == '"') // Already closed
          {
            record = record.substr(1);
            record = record.erase(record.size() - 1);
          }
          else // Not yet closed, but reached a comma
          {
            std::string tmp;
            std::getline(sstream, tmp, '"');
            
            record = record.substr(1);
            record += delimiter;
            record = record.append(tmp);
            
            std::getline(sstream, tmp, delimiter);
          }
          
        }
        data_set.set(record, row, col);
        col++;
      }
      
      row++;
      
    }
    
    return data_set;
  }
  catch (const std::exception &e)
  {
    throw e;
  }
}
