include iostream;
using namespace std;

class Transport {
public:
  virtual void config() {
    int seats;
    int weight;
  }
  virtual void info();
};

class Car:public Transport {
public:
  void config() {
    int wheels;
    
  }
  void info() {
    cout<<"Car with "<<wheels<<"wheels"<<endl;
  }
};

class Boat:public Transport {
public:
  void config() {
    int paddles;
  }
  void info() {
    cout<<"Boat with "<<paddles<<" paddles"<<endl;
  }
};

class Plain:public Transport {
public:
  void config() {
    int propellers;
  }
  void info() {
    cout<<"Plain with "<<propellers<<"propellers"<<endl;
  }
};

class Factory{
public:
    virtual Transport* create() = 0; //Чистая виртуальная функция показывает, что в производстве будет метод Create
    virtual ~Factory(){}  //Виртуальный деструктор
};

class CarFactory:public Factory {
public:
  Transport* create(){
        return new Car;
};
  
class BoatFactory:public Factory {
public:
  Transport* create(){
        return new Boat;
};
  
class PlaneFactory:public Factory {
public:
  Transport* create(){
        return new Plane;
};
  
Transport* Assembling(Factory *value){
    return value->create(); 
}
