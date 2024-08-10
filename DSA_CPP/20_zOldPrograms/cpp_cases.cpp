#include <iostream>
using namespace std;


class Label {  
public:  
    Label(const string& name, const string& address) { m_name = name; m_address = address; cout << "label ctor" << endl; }  
    string m_name;  
    string m_address;  
};  

class Box {  
public:  
    Box(int width, int length, int height){  
       m_width = width;  
       m_length = length;  
       m_height = height;  
		cout << "box ctor" << endl;
    }  
  
private:  
    int m_width;  
    int m_length;  
    int m_height;  
}; 

class StorageBox : public Box {  
public:  
    StorageBox(int width, int length, int height, Label label)   
        : Box(width, length, height), m_label(label){cout << "storage box ctor" << endl;}  
private:  
    Label m_label;  
};  
  
int main(){  
// passing a named Label  
    Label label1{ "some_name", "some_address" };  
    StorageBox sb1(1, 2, 3, label1);  
  
    // passing a temporary label  
    StorageBox sb2(3, 4, 5, Label{ "another name", "another address" });  
  
    // passing a temporary label as an initializer list  
    StorageBox sb3(1, 2, 3, {"myname", "myaddress"});  
} 