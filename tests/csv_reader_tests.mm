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

@property (nonatomic) mlkit::data::data_set data_set;

@end

@implementation csv_reader_tests

@synthesize data_set = _data_set;

- (void)setUp
{
  [super setUp];
  self.data_set = mlkit::io::csv_reader::read(mlkit_input_file_path("100-rows.csv"));
}

- (void)testCSVReaderWithMatrixNotation
{
  
  XCTAssertEqual(self.data_set.at(0, 0), 1);
  XCTAssertEqual(self.data_set.at(0, 1), "Lowell");
  XCTAssertEqual(self.data_set.at(0, 2), "MacDirmid");
  XCTAssertEqual(self.data_set.at(0, 4), "Male");
  XCTAssertEqual(self.data_set.at(0, 5), "244.142.125.198");
  
  XCTAssertEqual(self.data_set.at(49, 0), 50);
  XCTAssertEqual(self.data_set.at(49, 1), "Gilemette");
  XCTAssertEqual(self.data_set.at(49, 2), "Roobottom");
  XCTAssertEqual(self.data_set.at(49, 4), "Female");
  XCTAssertEqual(self.data_set.at(49, 5), "139.58.54.247");
  
  XCTAssertEqual(self.data_set.at(99, 0), 100);
  XCTAssertEqual(self.data_set.at(99, 1), "Dniren");
  XCTAssertEqual(self.data_set.at(99, 2), "Rowbottam");
  XCTAssertEqual(self.data_set.at(99, 4), "Female");
  XCTAssertEqual(self.data_set.at(99, 5), "182.73.42.239");
  
}

- (void)testCSVReaderCorrectColumnsAndRows
{
  
  XCTAssertEqual(self.data_set.ncols(), 6);
  XCTAssertEqual(self.data_set.nrows(), 100);
  
}

- (void)testCSVReaderWithColumnLiteralSupscript
{
  
  XCTAssertEqual(self.data_set.labels()[0], "id");
  XCTAssertEqual(self.data_set.labels()[1], "first_name");
  XCTAssertEqual(self.data_set.labels()[2], "last_name");
  XCTAssertEqual(self.data_set.labels()[3], "email");
  XCTAssertEqual(self.data_set.labels()[4], "gender");
  XCTAssertEqual(self.data_set.labels()[5], "ip_address");
  
  XCTAssertEqual(self.data_set["gender"][29], "Male");
  XCTAssertEqual(self.data_set["ip_address"][29], "148.51.192.228");
  
}

@end
