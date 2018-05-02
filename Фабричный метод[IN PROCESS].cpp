#include <iostream>
using namespace std;

class Transport {
public:
    int seats;
    int weight;
    virtual void info() = 0;
};

class Car:public Transport {
public:
    int wheels = 4;

    void info() {
        cout<<"Car with "<<wheels<<" wheels"<<endl;

    }
};

class Boat:public Transport {
public:
    int paddles = 2;

    void info() {
        cout<<"Boat with "<<paddles<<" paddles"<<endl;
    }
};

class Plane:public Transport {
public:
    int propellers = 2;

    void info() {
        cout<<"Plane with "<<propellers<<" propellers"<<endl;

    }
};

class Factory{
public:
    virtual Transport* create() = 0;
    virtual ~Factory(){}
};

class CarFactory:public Factory {
public:
    Transport* create() {
        return new Car;
    }
};

class BoatFactory:public Factory {
public:
    Transport* create() {
        return new Boat;
    }
};

class PlaneFactory:public Factory {
public:
    Transport* create() {
        return new Plane;
    }
};

Transport* Assembling(Factory *value) {
    return value->create();
}

int main(){
    CarFactory car;
    Factory *factory1 = &car;
    Transport *transport1 = Assembling(factory1);
    transport1->info();
    BoatFactory boat;
    Factory *factory2 = &boat;
    Transport *transport2 = Assembling(factory2);
    transport2->info();
    PlaneFactory plane;
    Factory *factory3 = &plane;
    Transport *transport3 = Assembling(factory3);
    transport3->info();
}
