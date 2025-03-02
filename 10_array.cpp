#include<iostream>
using namespace std;

void printarray(int arg[], int length)
{
    for (int n = 0; n < length; n++)
        cout << arg[n] << " ";

    cout << "\n";
}

void func()
{
    int arr[5];
    int arr2[5] = { 16,2,88, 40,12071 };
    int arr3[5] = { 10,20,30 };
    int arr4[] = { 16,2,77,40,12720 };
    int arr5[]{ 10,20,30 };

    arr4[3] = 123;

    for (int i = 0;i < 5;++i)
    {
        cout << arr3[i] << ", ";
    }
    cout << "\n";

    int w = 5, h = 3;
    int jimmy[w][h];

    for (int n = 0; n < w; n++)
    {
        for (int m = 0; m < h; m++)
        {
            jimmy[n][m] = (n + 1) * (m + 1);
        }
    }
}

void procedure(int myarray[][3][4]);

int main(int argc, char const* argv[])
{
    func();
    return 0;

    int arr4[] = { 16,2,77,40,12720 };
    printarray(arr4, 5);

    return 0;
}
