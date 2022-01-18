//
//  PageSizeClass.hpp
//  TaskXml
//
//  Created by Vlad Blotenko on 18.01.2022.
//

#ifndef PageSizeClass_hpp
#define PageSizeClass_hpp

#include <stdio.h>
#include <iostream>
 #include <vector>
 #include <string>
#include <fstream>
#include "pugixml.hpp"


 using namespace std;
using namespace pugi;

 class PageSize{
 private:
     string id;
     string width;
     string height;
 public:
     PageSize(){
         id = "0";
         width ="0";
         height = "0";
     }
     PageSize(string s1, string s2, string s3){
         id = s1;
         width  =s2;
         height  = s3;
     }
     string getId ()const {return id;}
     string getWidth()const{return width;}
     string getHeight()const{return height;}
     void setId(string newId){ id=newId;}
     void setWidth(string newWidth){ width=newWidth;}
     void setHeight(string newHeight){height=newHeight;}
     
     bool operator == (const PageSize & other){
         return (this->id==other.id &&
                 this->width==other.width
                 && this->height==other.height);
     }
 };

#endif /* PageSizeClass_hpp */
