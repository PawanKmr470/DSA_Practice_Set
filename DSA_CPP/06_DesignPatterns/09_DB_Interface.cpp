#include <iostream>
using namespace std;

class DatabaseConnection {
public:
    DatabaseConnection() { cout << "Base ctor called" << endl; }
    virtual ~DatabaseConnection() { cout << "Base dtor called" << endl; }

    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void query(const string &query) = 0;
};

class MySQLConnection : public DatabaseConnection {
public:
    MySQLConnection() { cout << "MySQL ctor called" << endl; }
    ~MySQLConnection() { cout << "MySQL dtor called" << endl; }

    void connect() override {
        cout << "Connecting to MySQL Database..." << endl;
    }

    void disconnect() override {
        cout << "Disconnecting from MySQL Database..." << endl;
    }

    void query(const string &query) override {
        cout << "Executing MySQL query : " << query << endl;
    }
};

class PostgreSQLConnection : public DatabaseConnection {
public:
    PostgreSQLConnection() { cout << "PostgreSQL ctor called" << endl; }
    ~PostgreSQLConnection() { cout << "PostgreSQL dtor called" << endl; }

    void connect() override {
        cout << "Connecting to PostgreSQL Database..." << endl;
    }

    void disconnect() override {
        cout << "Disconnecting from PostgreSQL Database..." << endl;
    }

    void query(const string &query) override {
        cout << "Executing PostgreSQL query : " << query << endl;
    }
};

int main() {
    DatabaseConnection *conn = new MySQLConnection();
    conn->connect();
    conn->query("SELECT * FROM users;");
    conn->disconnect();

    delete conn;

    conn = new PostgreSQLConnection();
    conn->connect();
    conn->query("SELECT * FROM customers;");
    conn->disconnect();
    
    delete conn;

    cout << "***************************************************************************" << endl;

    // Better to use Smart pointers for automatic memory manangement
    unique_ptr<DatabaseConnection> conn2 = make_unique<MySQLConnection>();
    conn2->connect();
    conn2->query("SELECT * FROM table1;");
    conn2->disconnect();

    conn2 = make_unique<PostgreSQLConnection>();
    conn2->connect();
    conn2->query("SELECT * FROM table2;");
    conn2->disconnect();

    return 0;
}

// Base ctor called
// MySQL ctor called
// Connecting to MySQL Database...
// Executing MySQL query : SELECT * FROM users;
// Disconnecting from MySQL Database...
// MySQL dtor called
// Base dtor called
// Base ctor called
// PostgreSQL ctor called
// Connecting to PostgreSQL Database...
// Executing PostgreSQL query : SELECT * FROM customers;
// Disconnecting from PostgreSQL Database...
// PostgreSQL dtor called
// Base dtor called
// ***************************************************************************
// Base ctor called
// MySQL ctor called
// Connecting to MySQL Database...
// Executing MySQL query : SELECT * FROM table1;
// Disconnecting from MySQL Database...
// Base ctor called
// PostgreSQL ctor called
// MySQL dtor called
// Base dtor called
// Connecting to PostgreSQL Database...
// Executing PostgreSQL query : SELECT * FROM table2;
// Disconnecting from PostgreSQL Database...
// PostgreSQL dtor called
// Base dtor called