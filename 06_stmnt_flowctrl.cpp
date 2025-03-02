#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n = 10;

    while (n > 0)
    {
        cout << n << ", ";
        --n;
    }

    cout << "liftoff!\n";

    string str;
    do {
        cout << "Enter text: ";
        getline(cin, str);
        cout << "You entered: " << str << '\n';
    } while (str != "goodbye");

    for (int n = 10; n > 0; n--)
    {
        cout << n << ", ";
    }

    cout << "liftoff!\n";

    int i = 0;
    for (n = 0, i = 10; n != i; ++n, --i)
    {
        cout << n << i << "\n";
    }

    string str2{ "Hello!" };
    for (char c : str2)
    {
        cout << "[" << c << "]";
    }
    cout << '\n';

    for (auto c : str)
        cout << "[" << c << "]";
    cout << '\n';
}