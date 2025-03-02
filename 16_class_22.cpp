#include <iostream>
using namespace std;

template <class T>
class MyClass
{
private:
    T element;

public:
    MyClass(T args) : element(args) {};
    T increase() { return ++element; };
    const T &get_element() const;
};

template <class T>
const T &MyClass<T>::get_element() const
{
    return *element;
}

template <>
class MyClass<char>
{
private:
    char element;

public:
    MyClass(char args) : element(args) {};
    char uppercase();
};

char MyClass<char>::uppercase()
{
    if ((element >= 'a') && (element <= 'z'))
    {
        element += 'A' - 'a';
        return element;
    }
}

int main(int argc, char const *argv[])
{
    MyClass<int> intclass(5);
    MyClass<char> charclass('i');

    cout << intclass.increase() << endl;
    cout << charclass.uppercase() << endl;

    return 0;
}
