cmake_minimum_required(VERSION 3.12)
project(mlkit)

set(CMAKE_CXX_STANDARD 14)

add_executable(mlkit main.cpp include/mlkit.h include/data.h src/cell.cpp include/cell.h include/io.h src/csv_reader.cpp include/csv_reader.h src/data_set.cpp include/data_set.h include/macros.h)

cmake_minimum_required(VERSION 3.12)
set(CMAKE_BUILD_TYPE Release)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(ml include/mlkit.h include/data.h src/cell.cpp include/cell.h include/io.h src/csv_reader.cpp include/csv_reader.h src/data_set.cpp include/data_set.h include/macros.h src/label_vector.cpp include/label_vector.h)