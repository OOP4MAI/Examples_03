#include <iostream>
#include <string>

#define UNUSED(value) (void)value

class Animal
{
protected:
    std::string name;

public:
    Animal(const char *val) : name(val){};
    const char *get_name() { return name.c_str(); }
};

class Moose : public Animal
{

public:
    Moose() : Animal("Moose"){};
    void run()
    {
        std::cout << name << " running" << std::endl;
    }
};

class Dog : public Animal
{

public:
    Dog() : Animal("Dog"){};
    void bark()
    {
        std::cout << "woof woof!" << std::endl;
    }
};

int main(int argc, char *argv[])
{

    Moose m;
    std::cout << m.get_name() << std::endl;
    m.run();

    Dog d;
    std::cout << d.get_name() << std::endl;
    d.bark();

    std::cout << std::endl
              << "Heap objects" << std::endl;
    Moose *ptr_moose = new Moose();

    std::cout << ptr_moose->get_name() << std::endl;
    ptr_moose->run();

    Animal *ptr_animal = (Animal*)ptr_moose;
    std::cout << ptr_animal->get_name() << std::endl;
    

    delete ptr_moose;

    UNUSED(argc);
    UNUSED(argv);
    return 1;
}