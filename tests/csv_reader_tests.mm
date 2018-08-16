//
//  csv_reader_tests.m
//  tests
//
//  Created by Nidhal DOGGA on 15/08/2018.
//  Copyright © 2018 Nidhal DOGGA. All rights reserved.
//


#import <XCTest/XCTest.h>
#import "mlkit_tests.h"
#import "mlkit.h"
#include <string>

@interface csv_reader_tests : XCTestCase

@property (nonatomic) mlkit::data::data_set hundred_rows_data_set;

@end

@implementation csv_reader_tests

@synthesize hundred_rows_data_set = _hundred_rows_data_set;

- (void)setUp
{
  [super setUp];
  self.hundred_rows_data_set = mlkit::io::csv_reader::read(mlkit_input_file_path("100-rows.csv"));
}

- (void)testCSVReaderWithMatrixNotation
{
  
  XCTAssertEqual(self.hundred_rows_data_set.at(0, 0), 1);
  XCTAssertEqual(self.hundred_rows_data_set.at(0, 1), "Lowell");
  XCTAssertEqual(self.hundred_rows_data_set.at(0, 2), "MacDirmid");
  XCTAssertEqual(self.hundred_rows_data_set.at(0, 4), "Male");
  XCTAssertEqual(self.hundred_rows_data_set.at(0, 5), "244.142.125.198");
  
  XCTAssertEqual(self.hundred_rows_data_set.at(49, 0), 50);
  XCTAssertEqual(self.hundred_rows_data_set.at(49, 1), "Gilemette");
  XCTAssertEqual(self.hundred_rows_data_set.at(49, 2), "Roobottom");
  XCTAssertEqual(self.hundred_rows_data_set.at(49, 4), "Female");
  XCTAssertEqual(self.hundred_rows_data_set.at(49, 5), "139.58.54.247");
  
  XCTAssertEqual(self.hundred_rows_data_set.at(99, 0), 100);
  XCTAssertEqual(self.hundred_rows_data_set.at(99, 1), "Dniren");
  XCTAssertEqual(self.hundred_rows_data_set.at(99, 2), "Rowbottam");
  XCTAssertEqual(self.hundred_rows_data_set.at(99, 4), "Female");
  XCTAssertEqual(self.hundred_rows_data_set.at(99, 5), "182.73.42.239");
  
}

- (void)testCSVReaderCorrectColumnsAndRows
{
  
  XCTAssertEqual(self.hundred_rows_data_set.ncols(), 6);
  XCTAssertEqual(self.hundred_rows_data_set.nrows(), 100);
  
}

- (void)testCSVReaderWithColumnLiteralSupscript
{
  
  XCTAssertEqual(self.hundred_rows_data_set.labels()[0], "id");
  XCTAssertEqual(self.hundred_rows_data_set.labels()[1], "first_name");
  XCTAssertEqual(self.hundred_rows_data_set.labels()[2], "last_name");
  XCTAssertEqual(self.hundred_rows_data_set.labels()[3], "email");
  XCTAssertEqual(self.hundred_rows_data_set.labels()[4], "gender");
  XCTAssertEqual(self.hundred_rows_data_set.labels()[5], "ip_address");
  
  XCTAssertEqual(self.hundred_rows_data_set["gender"][29], "Male");
  XCTAssertEqual(self.hundred_rows_data_set["ip_address"][29], "148.51.192.228");
  
}

- (void)testCSVReaderWithHugeCSVFile
{
  mlkit::data::data_set huge_data_set = mlkit::io::csv_reader::read(mlkit_input_file_path("reviews-dataset.csv"));
  
  XCTAssertEqual(huge_data_set["review"][0], "Story of a man who has unnatural feelings for a pig. Starts out with a opening scene that is a terrific example of absurd comedy. A formal orchestra audience is turned into an insane, violent mob by the crazy chantings of it's singers. Unfortunately it stays absurd the WHOLE time with no general narrative eventually making it just too off putting. Even those from the era should be turned off. The cryptic dialogue would make Shakespeare seem easy to a third grader. On a technical level it's better than you might think with some good cinematography by future great Vilmos Zsigmond. Future stars Sally Kirkland and Frederic Forrest can be seen briefly.");
  XCTAssertEqual(huge_data_set["rating"][0], 3);
  XCTAssertEqual(huge_data_set["rating"][1], 4);
  
}

- (void)testCSVReadPerformanceForHugeFile
{
  [self measureBlock:^
   {
     mlkit::io::csv_reader::read(mlkit_input_file_path("reviews-dataset.csv"));
   }];
}

@end
