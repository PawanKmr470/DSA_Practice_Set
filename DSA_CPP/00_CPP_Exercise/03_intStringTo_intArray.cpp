#include <iostream>
#include <sstream>              // Header file <sstream>
#include <string>
#include <vector>
using namespace std;

// Check << & >> operator overloading also for the use of istream & ostream
// getline() default delimiter is new line character i.e. '\n'
// better to use it with cin like - string line; getline(cin, line);
// Ref : https://akh1l.hashnode.dev/stringstream-and-getline-in-cpp

vector<int> stringToIntegerArray(const string& str) {
    vector<int> result;
    istringstream iss(str);             // istringstream is used

    int num;
    while (iss >> num) {
        result.push_back(num);
    }

    return result;
}

vector<string> wordBreak(const string& str) {
    vector<string> result;
    stringstream iss(str);               // istringstream can also be used

    string num;
    while (getline(iss, num, ' ')) {    // using getline
        result.push_back(num);
    }

    return result;
}

int main() {
    string numberString = "1 2 3 4 5";

    vector<int> integerArray = stringToIntegerArray(numberString);
    cout << "Integer array: ";
    for (int num : integerArray) {
        cout << num << " ";
    }
    cout << endl;


    vector<string> words = wordBreak(numberString);
    cout << "Words array : ";
    for (string &word : words) {
        cout << word << endl;
    }

    return 0;
}