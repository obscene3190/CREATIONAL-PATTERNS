#include <iostream>
#include <vector>
using namespace std;

class Pizza {
public:
    bool cheese = false, pepperoni = false, ketchup = false, potato = false, tomato = false, green = false, closed = false;
};

class Builder : public Pizza {
public:
    Pizza * pizza = new Pizza();
    virtual void addcheese() = 0;
    virtual void addpepperoni() = 0;
    virtual void addketchup() = 0;
    virtual void addpotato() = 0;
    virtual void addtomato() = 0;
    virtual void addgreen() = 0;
    virtual void addclosed()= 0;
    virtual Pizza* getPizza() {
        return pizza;
    }
    virtual void info() = 0;
};

class PepperoniBuilder : public Builder {
public:
    void addcheese() {
        cheese = true;
    }
    void addpepperoni() {
        pepperoni = true;
    }
    void addketchup() {
        ketchup = true;
    }
    void info() {
        cout<<"Pepperoni with cheese, pepperoni and ketchup"<<endl;
    }
};

class CalzoneBuilder : public Builder {
public:    
    void addcheese() {
        cheese = true;
    }
    void addketchup() {
        ketchup = true;
    }
    void addpotato() {
        potato = true;
    }
    void addtomato() {
        tomato = true;
    }
    void addclosed() {
         closed = true;
    }
    void info() {
        cout<<"Calzone with cheese, potato, tomato  and ketchup"<<endl;
    }
};

class FourCheesesBuilder : public Builder {
public:
    void addcheese() {
        cheese = true;
    }
    void addketchup() {
        ketchup = true;
    }
    void addgreen() {
        green = true;
    }
    void info() {
        cout<<"FourCheeses with cheese, green and ketchup"<<endl;
    }
};

class Cook {
public:
    Pizza * makepizza(Builder &builder) {
        builder.addcheese();
        builder.addpepperoni();
        builder.addketchup();
        builder.addpotato();
        builder.addtomato();
        builder.addgreen();
        builder.addclosed();
        return(builder.getPizza());
    }
};

int main() {
    Cook povar;
    PepperoniBuilder pepperoni;
    Pizza *pizza1 = povar.makepizza(pepperoni);
}
