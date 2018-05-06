#include <iostream>
#include <string>
using namespace std;


class Shape {
public:
    int X;
    int Y;
    string color;
    virtual Shape* clone() = 0;
    virtual void info() = 0;
    /*Shape(Shape &source) {
            X = source.X;
            Y = source.Y;
            color = source.color;
    }*/
    
};
// Конкретный прототип. Метод клонирования создаёт новый объект
// текущего класса, передавая в его конструктор ссылку на
// собственный объект. Благодаря этому операция клонирования
// получается атомарной — пока не выполнится конструктор, нового
// объекта ещё не существует. Но как только конструктор завершит
// работу, мы получим полностью готовый объект-клон, а не пустой
// объект, который нужно ещё заполнить.
class Rectangle : public Shape {
    int width;
    int height;
    Rectangle(Rectangle & source){ 
        // Вызов родительского конструктора нужен, чтобы
        // скопировать потенциальные приватные поля, объявленные
        // в родительском классе.
        //super(source)
            width = source.width;
            height = source.height;
        }
};
