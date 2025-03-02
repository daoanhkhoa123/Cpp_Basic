// const objects
#include <iostream>
using namespace std;

class MyClass
{
private:
    int value = 5;

public:
    MyClass() {};
    MyClass(int value) : value(value) {};
    ~MyClass() {};

    const int &get_const() { return value; };
    // int &const_get() const { return value; }; // error: const method can not return class variable
    const int &const_get_const() const { return value; }; // ok: forcing the return object is const
};

template <typename T>
void print(const T &t) { std::cout << t << endl; };

int main(int argc, char const *argv[])
{
    const MyClass const_myclass;
    MyClass myclass;

    // int constconst = const_myclass.get_const(); // error: const class object can not return non const
    // print(&constconst, sizeof(constconst));

    int constconstconst = const_myclass.const_get_const();
    print(constconstconst);

    return 0;
}
