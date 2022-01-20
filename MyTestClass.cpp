//
//  MyTestClass.cpp
//  testingObjectiveC!000
//
//  Created by Blotenko on 20.01.2022.
//

#include "MyTestClass.hpp"

void deleteByIndex(vector<MyClass>& v){
    unsigned long index = v.size()-1;
    v.erase(v.begin() + index);
    
}
void add(vector<MyClass>& v){
    v.push_back(MyClass());
}
