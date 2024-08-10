#include <iostream>
using namespace std;

// Interface or Library classes
class Vehicle {
    public:
        virtual void printVehicle() = 0;    // = 0 means it's implementation will definitely
        virtual ~Vehicle() {};              // be in derived class.

        // THIS IS FACTORY (CONCRETE FACTORY)
        static Vehicle* create(int);    // static bcz client can call it without any object.
                                        // this member function itself will create them.
};

class TwoWheeler : public Vehicle {
    public:
        void printVehicle() {
            cout << "This is a two wheeler." << endl;
        }
};

class ThreeWheeler : public Vehicle {
    public:
        void printVehicle() {
            cout << "This is a three wheeler." << endl;
        }
};

class FourWheeler : public Vehicle {
    public:
        void printVehicle() {
            cout << "This is a four wheeler." << endl;
        }
};

Vehicle* Vehicle::create(int type) {
    if (type == 2)
        return new TwoWheeler();
    else if (type == 3)
        return new ThreeWheeler();
    else if (type == 4)
        return new FourWheeler();
    else return NULL;
}


// Client or user class
class Client {
    private:
        Vehicle* pVehicle;
    public:
        Client(int type) {
            pVehicle = Vehicle::create(type);
        }

        ~Client() {
            delete pVehicle;
            pVehicle = NULL;
        }

        Vehicle* getVehicle() {
            return pVehicle;
        }
};

int main() {
    Client* pClient = new Client(4);
    Vehicle* pVehicle = pClient->getVehicle();
    pVehicle->printVehicle();
}
