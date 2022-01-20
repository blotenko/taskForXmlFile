//
//  TableViewController.m
//  testingObjectiveC!000
//
//  Created by Blotenko on 20.01.2022.
//

#import "TableViewController.h"
#include "MyTestClass.hpp"







@implementation TableViewController



- (id)init {
  self = [super init];
  if(self){
      _one.push_back(MyClass());
      _one.push_back(MyClass());
      _one.push_back(MyClass());
      _one.push_back(MyClass());
      _one.push_back(MyClass());
  }
  return self;
}



- (NSInteger)numberOfRowsInTableView:(NSTableView *)tableView {
    return self.one.size();
}

- (id)tableView:(NSTableView*)sender objectValueForTableColumn:(NSTableColumn*)tableColumn row:(long)rowIndex{
    return [NSString stringWithFormat:@"Row: %ld , Col: %@", rowIndex, [tableColumn identifier]];
}


-(NSView *)tableView:(NSTableView *)tableView viewForTableColumn:(NSTableColumn *)tableColumn row:(NSInteger)row {
    NSString *identifier = tableColumn.identifier;
    NSTableCellView *cell = [tableView makeViewWithIdentifier:identifier owner:self];
    NSString* result = [NSString stringWithUTF8String:_one[row].getStr().c_str()];
    cell.textField.stringValue = result;

    return cell;
}


@end
