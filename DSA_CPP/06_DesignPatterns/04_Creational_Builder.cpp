#include <iostream>
#include <string>
using namespace std;

// Car parts
class Wheel {
    public:
        int size;
};

class Engine {
    public:
        int horsepower;
};

class Body {
    public:
        string shape;
};

// Final product - a car
class Car {
    public:
        Wheel* wheel[4];
        Engine* engine;
        Body* body;

        void specifications() {
            cout << "body : " << body->shape << endl;
            cout << "engine : " << engine->horsepower << endl;
            cout << "tyre 1 size : " << wheel[0]->size << endl;
            cout << "tyre 2 size : " << wheel[1]->size << endl;
            cout << "tyre 3 size : " << wheel[2]->size << endl;
            cout << "tyre 4 size : " << wheel[3]->size << endl;
        }
};

// Builder is responsible for constructing the smaller parts
// getWheel ~ buildWheel
class Builder {
    public:
        virtual ~Builder(){};
        virtual Wheel* getWheel() = 0;
        virtual Engine* getEngine() = 0;
        virtual Body* getBody() = 0;
};

// This part is optional. Client can implement it in main().
// Responsible for executing the building steps in a particular sequence.
class Director {
    private:
        Builder* builder;
    public:
        void setBuilder(Builder* newBuilder) {
            builder = newBuilder;
        }

        Car* getCar() {
            Car* car = new Car();
            car->body = builder->getBody();
            car->engine = builder->getEngine();
            car->wheel[0] = builder->getWheel();
            car->wheel[1] = builder->getWheel();
            car->wheel[2] = builder->getWheel();
            car->wheel[3] = builder->getWheel();
            return car;
        }
};

// Concrete Builder for Jeep SUV cars
class JeepBuilder : public Builder {
    public:
        Wheel* getWheel() {
            Wheel* wheel = new Wheel();
            wheel->size = 22;
            return wheel;
        }

        Engine* getEngine() {
            Engine* engine = new Engine();
            engine->horsepower = 400;
            return engine;
        }

        Body* getBody() {
            Body* body = new Body();
            body->shape = "SUV";
            return body;
        }
};

int main() {
    Car* car;
    Director director;
    JeepBuilder jeepBuilder;

    // Build a jeep
    cout << "Building jeep..." << endl;
    director.setBuilder(&jeepBuilder);
    car = director.getCar();
    car->specifications();
}