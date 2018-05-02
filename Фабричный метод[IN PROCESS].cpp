#include <iostream>
using namespace std;

//Задача:
//Создание фабрики, на которой можно собирать любой транспорт
//Для примера возьмем такой транспорт: машина, лодка, самолет
//Особеннось фабричного метода позволяет добавить еще и другие виды транспорта, при этом не нужно будет переписывать весь код, а достаточно будет добавить новый класс и его фабрику, которые наследуют соответствующие классы


//Общий интерфейс объектов, которые будет создавать наша фабрика. Так как это транспорт, то он имеет сидения и вес(использовать их не будем)
class Transport {
public:
    int seats;
    int weight;
    virtual void info() = 0; //Виртуальная функция, которая будет предоставлять информацию о виде транспорта, у каждого своя
};

//Создаем наши объекты ,которые наследуют общий интерфейс и переопределяют нашу виртуальную функцию
//Отличительной чертой машины будут колеса, лодки - весла и самолета - пропеллеры.
//Чтобы в дальнейшем увидеть различие, добавлен метод info, который будет выводить особенности каждого типа транспорта
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

//Создаем класс общей "руководящей" фабрики, которая имеет виртуальный метод create, переопределяемый для каждой подфабрики
class Factory{
public:
    virtual Transport* create() = 0;
    virtual ~Factory(){}
};

//Создаем производство каждого отдельного типа
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

//Теперь можно создать функцию сборки, которая будет принимать фабрику и собирать нам транспорт, не зависимо от его типа
Transport* Assembling(Factory *value) {
    return value->create();
}


int main(){
    
    CarFactory car;//Создаем переменные каждого подкласса
    Factory *factory1 = &car;//Создаем указатели на объекты нужных типов
    Transport *transport1 = Assembling(factory1);//Создаем новый траспорт и собираем его на фабрике
    transport1->info();//Смотрим,что за объект мы собрали
    //ВЫВОД: Car with 4 wheels
    
    //Далее для каждого подкласса
    
    
    BoatFactory boat;
    Factory *factory2 = &boat;
    Transport *transport2 = Assembling(factory2);
    transport2->info();
    //ВЫВОД: Boat with 2 paddles
    
    
    PlaneFactory plane;
    Factory *factory3 = &plane;
    Transport *transport3 = Assembling(factory3);
    transport3->info();
    //ВЫВОД: Plane with 2 propellers
}
