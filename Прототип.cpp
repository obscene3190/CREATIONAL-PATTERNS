#include <iostream>
#include <string>
using namespace std;

//Прототип позволяет(как и фабрика) абстрагироваться от привязки нашего кода к конкретным классам
//Вместо этого создаем класс прототип, который используется для создания новых классов путем специальной команды клонирования

//класс прототип
class Shape {
public:
    int X;
    int Y;
    string color;
    Shape() {}
    Shape(Shape const & other) {
        X = other.X;
        Y = other.Y;
        color = other.color;
    }
    virtual Shape* clone() = 0;
    virtual void info() = 0;
    void showinfo(Shape * s) {
        s->info();
    }
};

// Конкретные прототипы
class Rectangle : public Shape {
public:
    int height;
    int weight;
    Rectangle(Rectangle const & other) : Shape(other) {
        height = other.height;
        weight = other.weight;
    }
    Shape* clone() override { 
        return new Rectangle(*this);
    }
    void info() {
        cout<<"Rectangle"<<endl;
    }
};

class Circle : public Shape {
public:    
    int radius;
    //Circle() : Shape() {};
    //Circle(Circle const & other) : Shape(other) {
        //radius = other.radius;
    //}
    Shape* clone() override {
        return new Circle(*this);
    }
    void info() {
        cout<<"Circle"<<endl;
    }
};
int main() {
     Circle * circle = new Circle();
     circle->X = 10;
     circle->Y = 20;
     circle->radius = 15;
     circle->info();
     Circle * anotherCircle = circle->clone();
     anotherCircle->info();
     
}
//Например, у нас будет массив с элементами класса Shape, тогда нам будет все равно, добавить туда треугольник
//или квадрат или любой другой конкретный прототип
