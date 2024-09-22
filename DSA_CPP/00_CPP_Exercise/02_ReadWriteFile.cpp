#include <iostream>
#include <fstream>              // Header file <fstream>
#include <string>
using namespace std;

void writeToFile(string filename) {
    fstream oFile;                                  // ofstream can also be used i.e. ofstream oFile;
    oFile.open(filename, ios::out);
    if (!oFile.is_open()) {
        cout << "Error in opening file." << endl;
        return;
    }

    oFile << "Hello !\n";                           // like cout : oFile << "Hello!\n";
    oFile << "This is second line." << endl;
    oFile << endl;
    oFile.close();

    cout << "File written." << endl;
}

void appendToFile(string filename) {
    fstream oFile;
    oFile.open(filename, ios::app);
    if (!oFile.is_open()) {
        cout << "Error in opening file." << endl;
        return;
    }

    oFile << "This is appended line.";
    oFile.close();

    cout << "File appended." << endl;
}

void readFromFile(string filename) {
    fstream iFile;                                  // ifstream can also be used i.e. ifstream iFile;
    string line;
    iFile.open(filename, ios::in);
    if (!iFile.is_open()) {
        cout << "Error in opening file." << endl;
        return;
    }

    // while (iFile >> line) {                      // This treats spaces as word break. Hence getline is better choice.
    //     cout << line << endl;
    // }

    while (getline(iFile, line)) {                  // like in : iFile >> line;
        cout << line << endl;
    }


    iFile.close();

    cout << "File read." << endl;
}

int main() {
    string filename = "pawan.txt";
    writeToFile(filename);
    appendToFile(filename);
    readFromFile(filename);
    int ret = remove(filename.c_str());         // filename.c_str() becuase remove expects const char * which is c style string.
    cout << "Delete status : " << ret << endl;
    return 0;
}