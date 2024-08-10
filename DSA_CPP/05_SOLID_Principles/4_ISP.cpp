#include <iostream>
using namespace std;

// Before applying ISP
class Printer {
    public:
        virtual void print() = 0;
        virtual void scan() = 0;
        virtual void fax() = 0;
};

class OnlyPrinter : public Printer {
    public:
        void print() override {
            // Print implementation
        }
        void scan() override {
            // Forced to implement this method
        }
        void fax() override {
            // Forced to implement this method
        }
};

class ScannerPrinter : public Printer {
    public:
        void print() override {
            // Print implementation
        }
        void scan() override {
            // Scan implementation
        }
        void fax() override {
            // Forced to implement this method
        }
};

//=================================================================

// After applying ISP
class Printer {
    public:
        virtual void print() = 0;
};

class Printable {
    public:
        virtual void print() = 0;   // check this second time pure virtual function declaration. It works
};
class Scannable {
    public:
        virtual void scan() = 0;
};
class Faxable {
    public:
        virtual void fax() = 0;
};

class OnlyPrinter : public Printable {
    public:
        void print() override {
            // Print implementation
        }
};

class ScannerPrinter : public Printable, public Scannable {
    public:
        void print() override {
            // Print implementation
        }
        void scan() override {
            // Scan implementation
        }
};

int main() {
    OnlyPrinter op;
}