int main(int argc, char const *argv[])
{
    {
        int arr1[10];

        int n = 10;
        int *arr2 = new int[n];
        delete[] arr2;
    }
    return 0;
}
