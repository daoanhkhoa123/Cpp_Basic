#include <iostream>
using namespace std;

int operate(int a, int b)
{
    return (a * b);
}

double operate(double a, double b)
{
    return (a / b);
}


template <class SomeType>
SomeType sum(SomeType a, SomeType b)
{
    return a + b;
}

template <class A>
A sum2(A a, A b)
{
    A result = a + b;
    return result;
}

template <class T, class U>
bool are_equal(T a, U b)
{
    return a == b;
}

template <class T, int n>
T fixed_multiply(T val)
{
    return val * n;
}

int main()
{
    int x = 5, y = 2;
    double n = 5.0, m = 2.0;
    cout << operate(x, y) << '\n';
    cout << operate(n, m) << '\n';

    x = sum<int>(10, 20);

    int i = 5, j = 6, k;
    double f = 2.0, g = 0.5, h;
    k = sum2<int>(i, j);
    h = sum2<double>(f, g);
    cout << k << '\n';
    cout << h << '\n';

    if (are_equal(10, 10.0) && are_equal<int, double>(10, 10.0))
        cout << "x and y are equal\n";
    else
        cout << "x and y are not equal\n";

    cout << fixed_multiply<int, 2>(10) << '\n';
    cout << fixed_multiply<int, 3>(10) << '\n';

    return 0;
}

