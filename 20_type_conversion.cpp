#include <iostream>

class A
{
};

class B
{
public:
    // conversion from A (constructor)
    B(const A &x) {};

    // conversion from A (assignment)
    B &operator=(const A &x) { return *this; };

    // conversion to A (type-cast operator)
    operator A()
    {
        return A();
    }
};

int main(int argc, char const *argv[])
{
    {
        short a = 2000;
        int b = a;
    }

    {
        A a;

        B b = a; // call constructor
        b = a;   // call assignment
        a = b;   // calls type-cast operator
    }
    return 0;
}
