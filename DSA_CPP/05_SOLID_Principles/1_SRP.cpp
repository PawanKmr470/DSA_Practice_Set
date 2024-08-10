#include <iostream>
using namespace std;

// SRP - Every Software Component should have one and only one responsibility

// Before applying SRP
class Invoice {
    public:
        void addInvoice() {};
        void deleteInvoice() {};
        void generateReport() {};
        void emailReport(){};
};

// After applying SRP
class Invoice {
    public:
        void addInvoice() {};
        void deleteInvoice() {};
};

class Report() {
    public:
        void generateReport(){};
}

class Email() {
    public:
        void emailReport() {};
};

//#######################################################

// Before applying SRP
class FileManager {
public:
    void saveToFile(string filename, string data) {
        ofstream file(filename);
        file << data;
        file.close();
    }
    vector<string> readFromFile(string filename) {
        vector<string> data;
        string line;
        ifstream file(filename);
        while (getline(file, line)) {
            data.push_back(line);
        }
        file.close();
        return data;
    }
    void listDirs() {};
    void listFiles() {};
};

// After applying SRP
class FileWriter {
public:
    void saveToFile(string filename, string data) {
        ofstream file(filename);
        file << data;
        file.close();
    }
};

class FileReader {
public:
    vector<string> readFromFile(string filename) {
        vector<string> data;
        string line;
        ifstream file(filename);
        while (getline(file, line)) {
            data.push_back(line);
        }
        file.close();
        return data;
    }
};

class FileManager : public FileReader, public FileWriter {
public:
    void listDirs() {};
    void listFiles() {};
};