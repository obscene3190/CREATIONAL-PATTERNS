#include <iostream>
using namespace std;

class Transport {
public:
  virtual void info() {
    int seats;
    int weight;
    }
};

class Car:public Transport {
public:
  void info() {
    int wheels;
    cout<<"Car with "<<wheels<<" wheels"<<endl;
  }
};

class Boat:public Transport {
public:
  void info() {
    int paddles;  
    cout<<"Boat with "<<paddles<<" paddles"<<endl;
  }
};

class Plane:public Transport {
public:

  void info() {
    int propellers;
    cout<<"Plane with "<<propellers<<" propellers"<<endl;
  }
};

class Factory{
public:
    virtual Transport* create() = 0; //Чистая виртуальная функция показывает, что в производстве будет метод Create
    virtual ~Factory(){}  //Виртуальный деструктор
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
    CarFactory car1;
    Factory *factory = &car1;
    Transport *transport1 = Assembling(factory);
    transport1->info();
}
