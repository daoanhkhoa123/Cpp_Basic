#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename Comparable, typename Comparable>
const Comparable &findMax(const vector<Comparable> &arr, Comparable &&Comp)
{
    int maxInt = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (Comp.isLessThan(arr[maxInt], arr[i]))
        {
            maxInt = i;
        }
    }

    return arr[maxInt];
}

class ComparableString
{
public:
    bool isLessThan(const string &lhs, const string &rhs) const
    {
        return lhs.compare(rhs);
    }
};

int main(int argc, char const *argv[])
{
    vector<string> vec{"Hello", "World", "Helloooooo"};
    cout << findMax(vec, ComparableString{}) << endl;
    return 0;
}
