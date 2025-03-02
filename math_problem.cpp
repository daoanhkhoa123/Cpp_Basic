#include <vector>
using namespace std;

int max3(const int x, const int y, const int z)
{
    int k = x;
    if (k < y)
    {
        k = y;
    }

    if (k < z)
    {
        k = z;
    }

    return k;
}

int maxSumRec(const vector<int> &a, const int left, const int right)
{
    if (left == right) // base
    {
        if (a[left] > 0)
        {
            return a[left];
        }
        else
        {
            return 0;
        }
    }

    int center = (left + right) / 2;
    int maxLeft = maxSumRec(a, left, center);
    int maxRight = maxSumRec(a, center + 1, right);

    int maxLeftBorder = 0, LeftBorder = 0;
    for (int i = center; i >= left; --i)
    {
        LeftBorder += a[i];
        if (LeftBorder > maxLeftBorder)
        {
            maxLeftBorder = LeftBorder;
        }
    }

    int maxRightBorder = 0, RightBorder = 0;
    for (int i = center; i <= right; ++i)
    {
        RightBorder += a[i];
        if (RightBorder > maxRightBorder)
        {
            maxRightBorder = RightBorder;
        }
    }

    return max3(maxLeft, maxRight, maxLeftBorder + maxRightBorder);
}

int maxSubsum(const vector<int> &a)
{
    return maxSumRec(a, 0, a.size() - 1);
}