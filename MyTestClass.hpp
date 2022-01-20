//
//  MyTestClass.hpp
//  testingObjectiveC!000
//
//  Created by Blotenko on 20.01.2022.
//

#ifndef MyTestClass_hpp
#define MyTestClass_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyClass{
private:
    string str;

public:
    MyClass(){
        str = "123 index";
    }
    
   string getStr(){
        
       return str;
    }
    
};



#endif /* MyTestClass_hpp */
