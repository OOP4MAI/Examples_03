#include <iostream>
#include <string>

#define UNUSED(value) (void)value

class A{
    private:
        std::string value;
    public:
        A() = delete;
        A(const A&) = delete;
        explicit A(const char* val) : value(val) {};
        A& operator=(const A&) = delete;

        void print() { std::cout << value << std::endl;}
};

int main(int argc, char *argv[])
{
    //A a1{};
    //a1.print();

    A a2("name");
    a2.print();

    A a3{"name2"};
    a3=a2;
    a3.print();

    UNUSED(argc);
    UNUSED(argv);
    return 1;
}