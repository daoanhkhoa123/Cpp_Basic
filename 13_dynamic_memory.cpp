#include <iostream>
#include <new>

int main(int argc, char const *argv[])
{
    {
        int *arr;
        arr = new int[5];
    }

    {
        int *arr;
        arr = new (std::nothrow) int[5];

        if (arr == nullptr)
        {
            
        }
        else
        {
            delete[] arr;
        }
        
    }

    return 0;
}
