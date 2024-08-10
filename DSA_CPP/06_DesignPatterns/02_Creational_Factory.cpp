#include <iostream>
using namespace std;

// Interface or Library classes
class Vehicle {
    public:
        virtual void printVehicle() = 0;    // = 0 means it's implementation will definitely
        virtual ~Vehicle() {};              // be in derived class.
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

// Client or user class
class Client {
    private:
        Vehicle* pVehicle;
    public:
        Client(int type) {
            if (type == 2)
                pVehicle = new TwoWheeler();
            else if (type == 3)
                pVehicle = new ThreeWheeler();
            else
                pVehicle = NULL;
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
    Client* pClient = new Client(2);
    Vehicle* pVehicle = pClient->getVehicle();
    pVehicle->printVehicle();
}

// Say, the library introduces a new class FourWheeler to incorporate three-wheeler vehicles also.
// The client will end up chaining a new else if in the conditional ladder to create objects
// of FourWheeler.
// So, each time a new change is made at the library side, 
// the Client would need to make some corresponding changes at its end and recompile the code.
