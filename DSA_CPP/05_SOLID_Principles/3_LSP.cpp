#include <iostream>
using namespace std;

// Before applying LSP
class Vehicle {
    public:
        virtual void startEngine() = 0;
};

class Car : public Vehicle {
    public:
        void startEngine() {};
};

class Bicycle : public Vehicle {
    public:
        void startEngine() {};  // Bicycle shouldn't be allowed to override startEngine() method
};

// After applying LSP
class Vehicle {
};

class MotorVehicle : public Vehicle {
    public:
        virtual void startEngine() = 0;
};

class ManualVehicle : public Vehicle {
    public:
        virtual void startMoving() = 0;
};

class Car : public MotorVehicle {
    public:
        void startEngine() {};
};

class Bicycle : public ManualVehicle {
    public:
        void startMoving() {};
};

//#######################################################


class Bird {
    public:
        virtual void fly() = 0;
};

class Crow : public Bird {
    public:
        void fly() {
            cout << "Crow flies" << endl;
        }
};

class Ostrich : public Bird {
    public:
        void fly() {
            throw logic_error("Not implemented");
        }
};

int main() {
    Bird* b1 = new Crow();
    b1->fly();

    // Bird* b2 = new Ostrich();        // This thorws exception
    // b2->fly();
}

//=================================================================

class Bird {
    public:
        virtual bool canFly() = 0;
        // This class should have more generic methods than fly
        // so that FlyingBird class & Ostrich class both can implement
};

class FlyingBird : public Bird {
    public:
        bool canFly() override {
            cout << "Can fly" << endl;
            return true;
        }
        virtual void fly() = 0;
};

class Crow : public FlyingBird {
    public:
        void fly() override {
            cout << "Crow flies" << endl;
        }
};

class Eagle : public FlyingBird {
    public:
        void fly() override {
            cout << "Eagle flies" << endl;
        }
};

class Ostrich : public Bird {
    public:
        bool canFly() override {
            cout << "Can not fly" << endl;
            return false;
        }
};

int main() {
    FlyingBird* fb;
    
    fb = new Crow();
    fb->canFly();
    fb->fly();

    fb = new Eagle();
    fb->canFly();
    fb->fly();

    // fb = new Ostrich();      // This will be compilatoin error

    Bird* b;
    b = new Ostrich();
    b->canFly();
    // b->fly();                   // This will be compilatoin error
}

// we can have another abstract class NonFlyingBird