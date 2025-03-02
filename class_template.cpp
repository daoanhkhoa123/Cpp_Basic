#include <iostream>
#include <string>
using namespace std;

// must have empty copy constructor
// must have empty copy assignment
// 
template <typename Comparable>
class MemoryCell
{
private:
    Comparable value;

public:
    explicit MemoryCell(const Comparable &init_value = Comparable()) : value(init_value) {};

    const Comparable &read() const { return value; };
    void write(const Comparable &obj) { value = obj; };
    void print() const { cout << value << endl; };

    ~MemoryCell() {};
};

int main(int argc, char const *argv[])
{
    MemoryCell<int> m1;
    MemoryCell<string> m2("hello");

    m1.write(5);
    m2.write(m2.read() + " world");

    m1.print();
    m2.print();

    return 0;
}