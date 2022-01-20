//
//  TableViewController.h
//  testingObjectiveC!000
//
//  Created by Blotenko on 20.01.2022.
//
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include "MyTestClass.hpp"

NS_ASSUME_NONNULL_BEGIN

@interface TableViewController : NSObject <NSTableViewDataSource, NSTableViewDelegate>

@property (nonatomic, weak) IBOutlet NSButton *addButton;
@property (weak) IBOutlet NSButton *deleteButton;
@property (nonatomic) vector<MyClass> one;


@end
NS_ASSUME_NONNULL_END
