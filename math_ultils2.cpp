#include <vector>
using namespace std;

template <typename Comparable>
int binary_search(const vector<Comparable> &a, const Comparable &obj)
{
    int lo = 0, hi = a.size() - 1;

    while (lo <= hi)
    {
        int center = (lo + hi) / 2;

        if (a[center] > obj)
        {
            hi = center - 1;
        }
        if (a[center] < obj)
        {
            lo = center + 1;
        }
        else
        {
            return center;
        }
    }

    return -1;
}

long long gdc(long long n, long long m)
{
    while (n != 0)
    {
        long long rem = m % n;

        m = n;
        n = rem;
    }

    return m;
}

long long pow(long long x, long long n)
{
    if (n == 0)
        return 1;

    if (n == 1)
        return x;

    if (n % 2 == 0)
        return pow(x * x, n / 2);

    if (n % 2 != 0)
        return pow(x * x, n / 2) * x;
}

int main(int argc, char const *argv[])
{

    return 0;
}
