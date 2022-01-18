
#include <iostream>
#include <vector>
#include <string>


#include "pugixml.hpp"
using namespace std;


class Xml{
private:
    string id;
    string width;
    string height;
public:
    Xml(){
        id = "0";
        width ="0";
        height = "0";
    }
    Xml(string s1, string s2, string s3){
        id = s1;
        width  =s2;
        height  = s3;
    }
    string getId(){return id;}
    string getWidth(){return width;}
    string getHeight(){return height;}
    void setId(string newId){ id=newId;}
    void setWidth(string newWidth){ width=newWidth;}
    void setHeight(string newHeight){height=newHeight;}
    void printALL(){
        cout<<"Id : "<<id<<endl;

    }
   
    friend bool operator== (const Xml &c1, const Xml &c2);
    
    
};

bool operator==(const Xml &c1, const Xml &c2){
    return (c1.id == c2.id &&
            c1.width == c2.width &&
            c1.height== c2.height);
}


void addElem(vector<Xml>& v){
    string id,width,height;
    cout<<"Id :";cin>>id;
    cout<<"width :";cin>>width;
    cout<<"height :";cin>>height;
    v.push_back(Xml(id,width,height));
}
bool deleteElem(vector<Xml>& v){
    int index;
    cout<<"enter which to delete : ";
    cin>>index;
    if(index<0 || index>=v.size()) return false;
    v.erase(v.begin() + index);
    return true;
}
void printAllElem(vector<Xml>& v){
    int i =0;
    for(auto  obj : v){
        cout<<i<<": ";
        obj.printALL();
        i++;
    }
}
void printByIndex(vector<Xml>& v){
    int n;
    cout<<"enter which to open : ";
    cin>>n;
    cout<<"Id : "<<v[n].getId()<<endl;
    cout<<"width : "<<v[n].getWidth()<<endl;
    cout<<"height : "<<v[n].getHeight()<<endl;
}
void compareTwo(vector<Xml>& v){
    int index1,index2;
    cout<<"Index first:";cin>>index1;
    cout<<"Index second:";cin>>index2;
    if(v[index1]==v[index2]) cout<<"Equal"<<endl;
    else cout<<"Not equal"<<endl;
}
void menu(){
    cout<<"1.Add"<<endl;
    cout<<"2.Delete"<<endl;
    cout<<"3.Compare"<<endl;
    cout<<"4.Print"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"Enter : ";
}



int main() {
    vector<Xml> xml;
    int count = 0;
    

    
    // интерфейс objective c
    
    // вывести данные с xml файла
    
    int choice=0;
    while(choice!=5){
        menu();
    cin>>choice;
    switch (choice) {
        case 1:
            addElem(xml);
            count++;
            break;
        case 2:
            if (count==0){
                cout<<"Impossible, first add"<<endl;
                break;}
            printAllElem(xml);
            if(deleteElem(xml))count--;
            else cout<<"Error index"<<endl;
            break;
        case 3:
            if (count<2){
                cout<<"Impossible, first add  two elem"<<endl;
                break;}
            printAllElem(xml);
            compareTwo(xml);
            break;
        case 4:
            if (count==0){
                cout<<"Impossible, first add"<<endl;
                break;}
            printAllElem(xml);
            printByIndex(xml);
            break;
            
        default:
            break;
    }
 }
    return 0;
}
