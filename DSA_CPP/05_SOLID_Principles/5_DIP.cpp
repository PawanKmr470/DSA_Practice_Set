#include <iostream>
using namespace std;

// Beofre applying DIP

class Database {
    public:
        void save(const string& data){
            // save data to database
        }
};

class Logger {
    private:
        Database& db;
    public:
        Logger(Database& db) : db(db) {};
        void log(const string& message) {
            // log message using db
            db.save(message);
        }
};

// In the Logger class, 
// the member variable database is a reference to an instance of the Database class.
// This means that the Logger class depends on a concrete implementation of the Database class,
// violating the Dependency Inversion Principle (DIP) of SOLID design.
// According to the DIP, 
// high-level modules should depend on abstractions rather than concrete implementations.

// After applying DIP

class DatabaseInterface {
    public:
        ~DatabaseInterface() {};
        virtual void save(string& data) = 0;
};

class Database {
    public:
        void save(const string& data) {
            // save data to database
        }
};

class Logger {
    private:
        DatabaseInterface& db;
    public:
        Logger(DatabaseInterface& db) : db(db) {};
        void log(const string& message) {
            // Log message using db
            db.save(message);
        }
};

// We modified the Logger class to depend on an abstract interface or base class 
// instead of the concrete Database class.
// This allows for greater flexibility, easier testing, 
// and the ability to swap out different database implementations 
// without modifying the Logger class.
