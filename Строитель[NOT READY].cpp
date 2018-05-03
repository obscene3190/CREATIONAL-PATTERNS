#include <iostream>
#include <vector>
using namespace std;

class Pizza {
public:
    bool cheese, pepperoni, ketchup, potato, tomato, green, closed;
    void info() {
        if (cheese) cout<<"cheese"<<endl;
        if (pepperoni) cout<<"pepperoni"<<endl;
        if (ketchup) cout<<"ketchup"<<endl;
        if (potato) cout<<"potato"<<endl;
        if (tomato) cout<<"tomato"<<endl;
        if (green) cout<<"green"<<endl;
        if (closed) cout<<"closed"<<endl;
    }
};

class Builder {
protected:
    Pizza * pizza;
public:
    virtual void create() = 0;
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
};

class PepperoniBuilder : public Builder {
public:
    void create() { pizza = new Pizza(); }
    void addcheese() {
        pizza->cheese = true;
    }
    void addpepperoni() {
        pizza->pepperoni = true;
    }
    void addketchup() {
        pizza->ketchup = true;
    }
     void addpotato() {
        pizza->potato = false;
    }
    void addtomato() {
        pizza->tomato = false;
    }
    void addgreen() {
        pizza->green = false;
    }
    void addclosed() {
        pizza->closed = false;
    }
};

class CalzoneBuilder : public Builder {
public:    
    void create() { pizza = new Pizza(); }
    void addcheese() {
        pizza->cheese = true;
    }
    void addpepperoni() {
        pizza->pepperoni = false;
    }
    void addketchup() {
        pizza->ketchup = true;
    }
    void addpotato() {
        pizza->potato = true;
    }
    void addtomato() {
        pizza->tomato = true;
    }
     void addgreen() {
        pizza->green = false;
    }
    void addclosed() {
        pizza->closed = true;
    }
};

class FourCheesesBuilder : public Builder {
public:
   void create() { pizza = new Pizza(); }
   void addcheese() {
        pizza->cheese = true;
    }
    void addpepperoni() {
        pizza->pepperoni = false;
    }
    void addketchup() {
        pizza->ketchup = true;
    }
    void addpotato() {
        pizza->potato = false;
    }
    void addtomato() {
        pizza->tomato = false;
    }
     void addgreen() {
        pizza->green = false;
    }
    void addclosed() {
        pizza->closed = true;
    }
};

class Cook {
public:
    Pizza * makepizza(Builder &builder) {
        builder.create();
        builder.addcheese();
        builder.addpepperoni();
        builder.addketchup();
        builder.addpotato();
        builder.addtomato();
        builder.addgreen();
        builder.addclosed();
        return(builder.getPizza());
    }
    void cookend() {
        cout<<endl<<"Bon appetite"<<endl<<endl;
    }
};

int main() {
    Cook povar;
    
    
    PepperoniBuilder pepperoni;
    Pizza *pizza1 = povar.makepizza(pepperoni);
    cout<<"We made pepperoni, which is: "<<endl;
    pizza1->info();
    povar.cookend();
    
    
    CalzoneBuilder calzone;
    Pizza *pizza2 = povar.makepizza(calzone);
    cout<<"We made calzone, which is: "<<endl;
    pizza2->info();
    povar.cookend();
    
    
    FourCheesesBuilder cheese4;
    Pizza *pizza3 = povar.makepizza(cheese4);
    cout<<"We made Four Cheeses, which is: "<<endl;
    pizza3->info();
    povar.cookend();
}
