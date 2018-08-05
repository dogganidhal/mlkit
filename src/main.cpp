
#include <iostream>
#include "mlkit.h"

int main()
{

  mlkit::data::data_set ds = mlkit::io::csv_reader::read(("1000-rows.csv"), ',');
  
  auto sets = ds.train_test_split(2.0 / 3.0);
  
  mlkit::data::data_set train_set = std::get<0>(sets), test_set = std::get<1>(sets);

  std::cout << "\nTRAIN SET --------------------------------------\n\n";
  
  for (size_t row = 0; row < train_set.nrows(); row++)
  {
    for (size_t col = 0; col < train_set.ncols(); col++)
    {
      std::cout << train_set.at(row, col);
      if (col < train_set.ncols() - 1)
        std::cout << ",";
    }
    if (row < train_set.nrows() - 1)
      std::cout << std::endl;
  }
  
  std::cout << "\n\nTEST SET --------------------------------------\n\n";
  
  for (size_t row = 0; row < test_set.nrows(); row++)
  {
    for (size_t col = 0; col < test_set.ncols(); col++)
    {
      std::cout << test_set.at(row, col);
      if (col < test_set.ncols() - 1)
        std::cout << ",";
    }
    if (row < test_set.nrows() - 1)
      std::cout << std::endl;
  }
  
  std::cout << std::endl;

}
