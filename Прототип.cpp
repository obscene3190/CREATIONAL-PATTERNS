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
    Shape(Shape const & other) {
        X = other.X;
        Y = other.Y;
        color = other.color;
    }
    virtual Shape* clone() = 0;
    virtual void info() = 0;
    /*static Shape * CreateShape(){
        
    } */
    
};

// Конкретные прототипы
class Rectangle : Shape {
    int height;
    int weight;
    Rectangle(Rectangle const & other) : Shape(other) {
        height = other.height;
        weight = other.weight;
    }
    Shape* clone() { 
        return new Rectangle(*this);
    }
    void info() {
        cout<<"Rectangle"<<endl;
    }
};

class Circle : public Shape {
    int radius;
    Circle(Circle const & other) : Shape(other) {
        radius = other.radius;
    }
    Shape* clone() {
        return new Circle(*this);
    }
    void info() {
        cout<<"Circle"<<endl;
    }
};
