#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename Comparable>
const Comparable &findMax(const vector<Comparable> &a)
{
    int maxIndex = 0;

    for (int i = 0; i < a.size(); ++i)
    {
        if (a[maxIndex] < a[i])
        {
            maxIndex = i;
        }
    }

    return a[maxIndex];
}

int main(int argc, char const *argv[])
{
    vector<int> vint(37);
    vector<double> v2(40);
    vector<string> v3(80);

    cout << findMax(vint) << endl; // OK: Comparable = int
    cout << findMax(v2) << endl;   // OK: Comparable = double
    cout << findMax(v3) << endl;   // OK: Comparable = string

    return 0;
}
