#include <iostream>

template <typename T>
class Test
{
private:
    T x;

public:
    class ClassA
    {
    private:
        T iter;

    public:
        template <typename Comparable>
        friend std::ostream &operator<<(std::ostream &out, const typename Test<Comparable>::ClassA &obj);
    };
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const typename Test<T>::ClassA &obj)
{
    out << obj.iter;
    return out;
};

int main(int argc, char const *argv[])
{
    Test<int>::ClassA t;
    std::cout << t << std::endl;
    return 0;
}
