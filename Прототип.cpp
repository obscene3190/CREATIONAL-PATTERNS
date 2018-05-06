#include <iostream>
#include <string>
using namespace std;


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
    Shape* clone() {
        return new Circle(*this);
    }
    void info() {
        cout<<"Circle"<<endl;
    }
};

