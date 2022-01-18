
#include "PageSizeClass.hpp"

 void addElem(vector<PageSize>& v,string s1,string s2,string s3){
     v.push_back(PageSize(s1,s2,s3));
 }

 bool deleteElem(vector<PageSize>& v){
     int index;
     cout<<"enter which to delete : ";
     cin>>index;
     if(index<0 || index>=v.size()) return false;
     v.erase(v.begin() + index);
     return true;
 }

 void printAllElem(const vector<PageSize>& v){
     int i =0;
     for(auto  obj : v){
         cout<<i<<": ";
         cout<<obj.getId()<<endl;
         i++;
     }
 }

 bool printByIndex (const vector<PageSize>& v){
     int n;
     cout<<"enter which to open : ";
     cin>>n;
     if(n<0 || n> v.size()) return false;
     cout<<"Id : "<<v[n].getId()<<endl;
     cout<<"width : "<<v[n].getWidth()<<endl;
     cout<<"height : "<<v[n].getHeight()<<endl;
     return true;
 }

 void compareTwo(vector<PageSize>& v){
     int index1,index2;
     cout<<"Index first:";cin>>index1;
     cout<<"Index second:";cin>>index2;
     if(v[index1] == v[index2]) cout<<"Equal"<<endl;
     else cout<<"Not equal"<<endl;
 }

vector<PageSize> loadFromFile(char* s){
    vector<PageSize> xml;

    xml_document doc;
    if (!doc.load_file(s)) return xml;
    xml_node tools = doc.child("PageSizeList");
    
    for (xml_node_iterator it = tools.begin(); it!= tools.end(); ++it){
        cout << "PageSize:"<<endl;
        string s1("0"),s2("0"),s3("0");
        for (xml_node_iterator it2 = it->begin(); it2!= it->end(); ++it2){
            cout <<  it2->name()<<" = "<<it2->child_value()<<endl;
            if(s1=="0") s1=it2->child_value();
            else if(s2=="0") s2=it2->child_value();
            else{ s3=it2->child_value();addElem(xml, s1, s2, s3);}
        }
        cout<<endl;
    }
    cout << endl;
    cout << endl;
    return xml;
    
}



void mainMenu(){
    cout<<"1.Add"<<endl;
    cout<<"2.Delete"<<endl;
    cout<<"3.Compare"<<endl;
    cout<<"4.Print"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"Enter : ";
}



int menu(){
    int choice;
    cout<<"1. BBC"<<endl;
    cout<<"2. DC"<<endl;
    cout<<"3. MF"<<endl;
    cout<<"Enter which doc do you want to use : ";
    cin>>choice;
    if (choice>3 && choice<0) return -1;
    return choice;
}




 int main() {
     vector<PageSize> xml;
    
     // интерфейс objective c
     
     
     char* s = nullptr;
     switch (menu()) {
         case 1:
             s="Paper_Formats_PageSize_BCC.xml";
             break;
         case 2:
             s="Paper_Formats_PageSize_DC.xml";
             break;
         case 3:
             s="Paper_Formats_PageSize_MF.xml";
             break;
         default:
             break;
     }
     
    xml = loadFromFile(s);
     
     
     int count = 8;
     int choice=0;
    
        while(choice!=5){
            mainMenu();
        cin>>choice;
        switch (choice) {
             case 1:
            {string id,width,height;
                    cout<<"Id :";cin>>id;
                    cout<<"width :";cin>>width;
                    cout<<"height :";cin>>height;
                addElem(xml,id,width,height);
                count++;}
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
