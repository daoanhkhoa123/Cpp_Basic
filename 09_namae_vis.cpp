// inner block scopes
#include <iostream>
using namespace std;

int GLOBALl = 68;

namespace myNamespace
{
    int value() { return 5; }
    const double pi = 3.1416;
}

namespace myNameisSquare
{
    int age = 19;
    const double pi = 709;
}

namespace Trieu = myNameisSquare;

int main() {
    int x = 10;
    int y = 20;
    {
        int x;   // ok, inner scope.
        x = 50;  // sets value to inner x
        y = 50;  // sets value to (outer) y
        cout << "inner block:\n";
        cout << "x: " << x << '\n';
        cout << "y: " << y << '\n';
    }
    cout << "outer block:\n";
    cout << "x: " << x << '\n';
    cout << "y: " << y << '\n';

    cout << myNameisSquare::pi << "\n";
    cout << myNameisSquare::pi << "\n";

    {
        using namespace myNameisSquare;
        cout << age << "\n";
    }

    {
        using namespace myNamespace;
        cout << value() << "\n";
    }

    cout << GLOBALl << '\n';
    cout << y << '\n';

    return 0;
}
