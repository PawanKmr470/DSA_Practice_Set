#include <iostream>
#include <vector>
#include <sstream>              // Header file <sstream>
#include <string>

using namespace std;

vector<int> stringToIntegerArray(const string& str, int& kval) {
    vector<int> result;
    istringstream iss(str);

    int num;
    while (iss >> num) {
        result.push_back(num);
        if (iss.peek() == ',' || iss.peek() == '.') {
            iss.ignore();
        }
        else if (iss.peek() == ';') {
            iss.ignore();
            iss >> kval;
        }
    }

    return result;
}

int main() {
    int k = 0;
    string numberString = "12, 34, 56; 78";
    vector<int> integerArray = stringToIntegerArray(numberString, k);

    cout << "Integer array: ";
    for (int num : integerArray) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Value of k : " << k << endl;

    return 0;
}