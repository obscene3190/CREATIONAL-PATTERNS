#include <iostream>
#include <vector>
using namespace std;

class Pizza {
public:
    bool cheese = false, pepperoni = false, ketchup = false, potato = false, tomato = false, green = false, closed = false;
};

class Builder : public Pizza {
    virtual void addcheese() = 0;
    virtual void addpepperoni() = 0;
    virtual void addketchup() = 0;
    virtual void addpotato() = 0;
    virtual void addtomato() = 0;
    virtual void addgreen() = 0;
    virtual void addclosed()= 0;
    virtual void info() = 0;
};

class PepperoniBuilder : public Builder {
    virtual void addcheese() {
        cheese = true;
    }
    virtual void addpepperoni() {
        pepperoni = true;
    }
    virtual void addketchup() {
        ketchup = true;
    }
    void info() {
        cout<<"Pepperoni with cheese, pepperoni and ketchup"<<endl;
    }
};

class CalzoneBuilder : public Builder {
    virtual void addcheese() {
        cheese = true;
    }
    virtual void addketchup() {
        ketchup = true;
    }
    virtual void addpotato() {
        potato = true;
    }
    virtual void addtomato() {
        tomato = true;
    }
    virtual void addclosed() {
         closed = true;
    }
    void info() {
        cout<<"Calzone with cheese, potato, tomato  and ketchup"<<endl;
    }
};

class FourCheesesBuilder : public Builder {
    virtual void addcheese() {
        cheese = true;
    }
    virtual void addketchup() {
        ketchup = true;
    }
    virtual void addgreen() {
        green = true;
    }
    void info() {
        cout<<"FourCheeses with cheese, green and ketchup"<<endl;
    }
};
