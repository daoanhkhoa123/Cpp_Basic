#include <iostream>
using namespace std;

int addition(int a, int b)
{
    int r;
    r = a + b;
    return r;
}

int subtraction(int a, int b)
{
    int r;
    r = a - b;
    return r;
}

void duplicate(int& a, int& b, int& c)
{
    a *= 2;
    b *= 2;
    c *= 2;
}

string concatenate(const string& a, const string& b)
{
    return a + b;
}

inline string concatenate2(const string& a, const string& b)
{
    return a + b;
}

int divide(int a, int b = 2)
{
    int r;
    r = a / b;
    return (r);
}

void odd(int x);
void even(int);

long factorial(long a)
{
    if (a > 1)
        return (a * factorial(a - 1));
    else
        return 1;
}

int main()
{
    int x = 5, y = 6, z;
    z = addition(5, 3);
    cout << "The result is " << z;


    z = subtraction(7, 2);
    cout << "The first result is " << z << '\n';
    cout << "The second result is " << subtraction(7, 2) << '\n';
    cout << "The third result is " << subtraction(x, y) << '\n';
    z = 4 + subtraction(x, y);
    cout << "The fourth result is " << z << '\n';

    duplicate(x, y, z);

    cout << "x=" << x << ", y=" << y << ", z=" << z;

    cout << divide(12) << '\n';
    cout << divide(20, 4) << '\n';

    long number = 9;
    cout << number << "! = " << factorial(number);

    return 0;
}

void odd(int x)
{
    if ((x % 2) != 0) cout << "It is odd.\n";
    else even(x);
}

void even(int x)
{
    if ((x % 2) == 0) cout << "It is even.\n";
    else odd(x);
}