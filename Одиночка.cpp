
//Паттерн необходим для содержания только одного объекта нашего класса, 
//при этом делая конструкторы недоступными для пользователя

//Классическая реализация
//Недостаток: придется вручную удалять наш объект
class Singleton1
{
  private:
    static Singleton1 * one;
    Singleton1() {}
    Singleton1( const Singleton1& );  
    Singleton1& operator=( Singleton1& );
  public:
    static Singleton1 * getNew() {
        if(!one)           
            one = new Singleton1();
        return one;
    }
};

//Реализация, предложенная Скоттом Мэйерсом(Scott Meyers)
//Объект сам уничтожится после завершения программы, тк он статический
//Недостатки: сложности создания объектов производных классов и невозможность безопасного доступа 
//нескольких клиентов к единственному объекту в многопоточной среде.
class SingletonScott
{
private: 
    SingletonScott() {}
    SingletonScott( const SingletonScott&);  
    SingletonScott& operator=( SingletonScott& );
public:
    static SingletonScott& getNew() {
        static SingletonScott  one;
        return one;
    }    
}; 

//Улучшенная реализация
//Добавлен специальный метод для автоматического удаления
class Singleton;
  
class SingletonDestroyer
{
  private:
    Singleton* p_instance; //это переменная, которая будет удаляться и в которую будет перезаписываться наша
  public:    
    ~SingletonDestroyer(); //удаляет переменную
    void initialize( Singleton* p );//переписывает переменные, чтобы удалить нашу
};
  
class Singleton
{
  private:
    static Singleton* p_instance;
    static SingletonDestroyer destroyer;
  protected: 
    Singleton() { }
    Singleton( const Singleton& );
    Singleton& operator=( Singleton& );
   ~Singleton() { }
    friend class SingletonDestroyer;
  public:
    static Singleton& getInstance();
};
    
SingletonDestroyer::~SingletonDestroyer() {   
    delete p_instance; 
}
void SingletonDestroyer::initialize( Singleton* p ) {
    p_instance = p; //переписывается адрес, по которому будет удаляться данные
}
Singleton& Singleton::getInstance() {
    if(!p_instance)     {
        p_instance = new Singleton();
        destroyer.initialize( p_instance);  //при создании объекта будет инициализироваться дестроер, таким образом делая 
        //автоматическим удаление нашего объекта после завершения программы    
    }
    return *p_instance;
}
