#include <iostream>
using namespace std;

void func()
{
    int x;
    int *p1 = &x;             // non-const pointer to non-const int
    const int *p2 = &x;       // non-const pointer to const int
    int *const p3 = &x;       // const pointer to non-const int
    const int *const p4 = &x; // const pointer to const int
    const int *p2a = &x;      //      non-const pointer to const int
    int const *p2b = &x;      // also non-const pointer to const int

    const char *str = "hello";

    char a;
    char *b;
    char **c;
    a = 'z';
    b = &a;
    c = &b;
}

void increase(void *data, int psize)
{
    if (psize == sizeof(char))
    {
        char *pchar;
        pchar = (char *)data; // cast to char pointer
        ++(*pchar);
    }
    else if (psize == sizeof(int))
    {
        int *pint;
        pint = (int *)data;
        ++(*pint);
    }
}

int addition(int a, int b)
{
    return (a + b);
}

int subtraction(int a, int b)
{
    return (a - b);
}

int operation(int x, int y, int (*func)(int, int))
{
    int g = (*func)(x, y);
    return g;
}

int main(int argc, char const *argv[])
{
    int x, y;
    int *p = &x;
    *p = 10;

    p = &y;
    *p = 20;

    cout << "firstvalue is " << x << '\n';
    cout << "secondvalue is " << y << '\n';

    int *px = &x, *py = &y;

    *px = 80;
    *py = *px; // = 80

    px = py; // = &y
    *px = 90;

    cout << "firstvalue is " << x << '\n';
    cout << "secondvalue is " << y << '\n';

    int arr[5];
    int *pa;
    pa = arr;

    *pa = 10;

    pa = &arr[2];
    *pa = 30;
    pa = arr + 3;
    *pa = 40; // arr[3]
    pa = arr;
    *(pa + 4) = 50; // arr[4]

    for (int n = 0; n < 5; n++)
        cout << arr[n] << ", ";

    cout << "\n";

    char a = 'x';
    int b = 1603;
    increase(&a, sizeof(a));
    increase(&b, sizeof(b));
    cout << a << ", " << b << '\n';

    int *p2 = 0;
    int *q = nullptr;
    int *r = NULL;

    int m, n;
    int (*minus)(int, int) = subtraction;

    m = operation(7, 5, addition);
    n = operation(20, m, minus);

    cout << n << "\n";
    return 0;
}
