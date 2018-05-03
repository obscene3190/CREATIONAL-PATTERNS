#include <iostream>
#include <vector>
using namespace std;
//Пример на основе примера из cpp-reference

//Абстрактная фабрика: позволяет создавать семейства связанных объектов, не привязываясь к конкретным классам создаваемых объектов
//Задача: создать классы армий разных стран, при условии, что войны одной страны не могут быть в армии другой страны

// Сначала создаем абстрактные базовые классы всех возможных видов воинов, в данном примере будут Солдат и Снайпер
//Естественно, в зависимости от армии, можно добавить еще какие-то классы войнов
class Soldier
{
  public:
    virtual void info() = 0;     
    virtual ~Soldier() {}
};
  
class Sniper
{
  public:
    virtual void info() = 0;
    virtual ~Sniper() {}
};

// Теперь создаем классы всех видов армии, например, Канады и США, соответственно имеющие свои особенности, но
//т.к. это по прежнему войны, то они наследуют базовый класс. Для различия добавим им выводы их "должностей".
class CanadaSoldier: public Soldier
{
  public:
    void info() { 
      cout << "CanadaSoldier" << endl; 
    }
};
  
class CanadaSniper: public Sniper
{
  public:
    void info() { 
      cout << "CanadaSniper" << endl; 
    }
};   
  
// Классы всех видов 2 семейства(США)
class USASoldier: public Soldier
{
  public:
    void info() { 
      cout << "USASoldier" << endl; 
    }
};
  
class USASniper: public Sniper
{
  public:
    void info() { 
      cout << "USASniper" << endl; 
    }
};   
  
  
// Абстрактная фабрика для производства войнов, можем создавать Солдата и Снайпера
class ArmyFactory
{
  public:    
    virtual Soldier* createSoldier() = 0;
    virtual Sniper* createSniper() = 0;
    virtual ~ArmyFactory() {}
};
  
  
// Фабрика для создания воинов 1 семейства(Канада) ,создающая войнов из Канады
class CanadaArmyFactory: public ArmyFactory
{
  public:    
    Soldier* createSoldier() { 
      return new CanadaSoldier; 
    }
    Sniper* createSniper() { 
      return new CanadaSniper; 
    }
};
  
  
// Фабрика для создания воинов 2 семейства(США), создающая войнов из США
class USAArmyFactory: public ArmyFactory
{
  public:    
    Soldier* createSoldier() { 
      return new USASoldier; 
    }
    Sniper* createSniper() { 
      return new USASniper; 
    }
};
  
  
// Класс, отражающий строение армии
class Army 
{
  public:
    vector<Soldier*> soldiers; //отряд солдат
    vector<Sniper*> snipers; //отряд снайперов
    void info() {   
      unsigned int i;
      for(i = 0; i<soldiers.size(); ++i) soldiers[i]->info(); 
      for(i = 0; i<snipers.size(); ++i) snipers[i]->info();
    }
    ~Army() {
      unsigned int i;
      for(i=0; i<soldiers.size(); ++i) delete soldiers[i]; 
      for(i=0; i<snipers.size(); ++i) delete snipers[i]; 
    }   
};
  
  
// Здесь создается армия той или иной стороны
class Game
{
  public:    
    Army* createArmy( ArmyFactory& factory ) {   
      Army* p = new Army;
      p->soldiers.push_back( factory.createSoldier());
      p->snipers.push_back( factory.createSniper());
      return p;
    }   
};
  
  
int main()
{        
    Game game;
    CanadaArmyFactory ca_factory;
    USAArmyFactory usa_factory;
     
    Army * ca = game.createArmy( ca_factory);
    Army * usa = game.createArmy( usa_factory);
    cout << "Canada army:" << endl;
    ca->info();
    cout << "\nUSA army:" << endl;
    usa->info();
}

//ВЫВОД
//Canada army:
//CanadaSoldier
//CanadaSniper

//USA army:
//USASoldier
//USASniper
