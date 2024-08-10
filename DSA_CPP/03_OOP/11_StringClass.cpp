#include <iostream>
using namespace std;

// default ctor
// copy ctor
// copy assignment ctor     Rule of 3 till here
// move ctor
// move assignemnt ctor     Rule of 5 till here
// dtor

// The rule of 3/5 is also referred to as the rule of 0/3/5. 
// The zero part of the rule states that you are allowed to not write 
// any of the special member functions when creating your class.

// Ref - https://www.geeksforgeeks.org/how-to-create-a-custom-string-class-in-c-with-basic-functionalities/

class String {
    private:
        char* res;
        unsigned int len;
    public:
        // Default ctor
        String() {
            len = 0;
            res = nullptr;
        }
        ~String() {
            if (res) {
                delete[] res;
                res = nullptr;  // remove chances of dangling pointer
                len = 0;
            }
        }

        // Parameterised ctor
        String(const char* str) {
            len = strlen(str);
            res = new char[len + 1];
            strcpy(res, str);
        }

        // Copy ctor
        String(const String& str) {
            len = str.len;
            res = new char[len + 1];
            strcpy(res, str.res);
        }

        // Copy assignement operator
        String& operator=(const String& str) {
            if (this != &str) {                 // this is pointer to current object
                char* temp = res;
                len = str.len;
                res = new char[len + 1];
                strcpy(res, str.res);
                if (temp) {
                    delete[] temp;                  // we need to delete previous allocation
                }                                   // BUT only after assignment succeeds. IMPORTANT
            }
            return *this;
        }

        // Copy assignment operator with CAS idiom (copy-and-swap idiom)
        // argument will call copy ctor which will create new object
        // then swap that object with this.

        // String& operator=(String str) {
        //     myswap(this, str);
        //     return *this;
        // }

        // void myswap(String& str1, String& str2) {
        //     swap(str1.len, str2.len);
        //     swap(str1.res, str2.res);
        // }

        // Move ctor
        String(String&& str) {
            len = str.len;
            res = str.res;
            str.len = 0;
            str.res = nullptr;
        }

        // Move assignment ctor
        String& operator=(String&& str) {
            if (this != &str) {
                len = str.len;
                if (res) {
                    delete[] res;
                }
                res = str.res;
                str.len = 0;
                str.res = nullptr;
            }
            return *this;
        }

        unsigned int length() { return len; }

        // Friend functions are not a member of the class and hence they do not have ‘this’ pointer.
        // When we overload a unary operator, we need to pass one argument.
        // When we overload a binary operator, we need to pass two arguments.
        friend ostream& operator<<(ostream& out, const String& str);
        friend istream& operator>>(istream& in, const String& str);
};

ostream& operator<<(ostream& out, const String& str) {
    if (str.res) {              // String str1; cout << str1 << endl; avoid segmentation fault
        out << str.res;
    }
    return out;
}

istream& operator>>(istream& in, String& str) {
    char* buf = new char[1000];
    memset(&buf[0], 0, sizeof(buf));
    in >> buf;
    str = String(buf);
    delete[] buf;
    return in;
}

int main() {
    String str1;    // default ctor
    String str2 = "hello";      // parameterized ctor
    String str3 = str2;         // copy ctor [same as String str3(str2)]. Take care of str3 = str3 self assignment
    String str4;
    str4 = str3;                // copy assignment ctor
    int len = str4.length();
    cout << len << endl;
    cout << str4 << " " << str3 << endl;
    cin >> str1;
    cout << str1 << endl;
    String str5 = std::move(str4);   // move ctor
    String str6;
    str6 = std::move("world");       // move assignment ctor
    cout << str6 << endl;
    return 0;

    // String str1("Hello world");
    // String str2;
    // str2 = str1;
    // cout << str2 << endl;
}