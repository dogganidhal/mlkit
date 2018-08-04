
#include <iostream>
#include "mlkit.h"

using namespace mlkit::io;
using namespace mlkit::data;

int main()
{

  data_set ds = mlkit::io::csv_reader::read(("tiny.csv"), ';');
  
  for (size_t row = 0; row < ds.nrows(); row++)
  {
    for (size_t col = 0; col < ds.ncols(); col++)
    {
      std::cout << ds.at(row, col);
      if (col < ds.ncols() - 1)
        std::cout << ",";
    }
    
    if (row < ds.nrows() - 1)
      std::cout << std::endl;
    
  }

}
