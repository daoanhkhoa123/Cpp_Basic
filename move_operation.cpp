#include <iostream>
#include <vector>
#include <string>
using namespace std;

void swap(vector<string> &x, vector<string> &y)
{
    vector<string> tmp = static_cast<vector<string> &&>(x);
    x = static_cast<vector<string> &&>(y);
    y = static_cast<vector<string> &&>(tmp);
}

void swap2(vector<string> &x, vector<string> &y)
{
    vector<string> tmp = std::move(x);
    x = std::move(y);
    y = std::move(tmp);
}

class ClassContainOnlyPointer
{
private:
    int *p;

public:
    ClassContainOnlyPointer(const ClassContainOnlyPointer &obj);            // copy constructor
    ClassContainOnlyPointer(ClassContainOnlyPointer &obj);                  // move constructor
    ClassContainOnlyPointer &operator=(ClassContainOnlyPointer &&obj);      // move assignment
    ClassContainOnlyPointer &operator=(const ClassContainOnlyPointer &obj); // copy assignment

    ~ClassContainOnlyPointer();
};

class Incell
{
private:
    int value;

public:
    Incell(const Incell &obj) = delete;            // no copy constructor
    Incell(Incell &&obj) = delete;                 // no move constructor
    Incell &operator=(const Incell &obj) = delete; // no copy assignment
    Incell &operator=(Incell &&obj) = delete;      // no move assingment
    ~Incell() = delete;
};

class IntPointeClass
{
private:
    int *value;

public:
    explicit IntPointeClass(int value = 0) { this->value = new int(value); };

    int read() const { return *value; }

    // void write(int &x) { value = &x; } // move operator
    void write(const int &x)
    {
        int num = x;
        value = &num;
    }

    void print() { cout << *value << endl; }

    // C++ 11 only
    // IntPointeClass &operator=(IntPointeClass &obj)
    // {
    //     IntPointeClass tmp = obj;
    //     std::swap(*this, tmp);
    //     return *this;
    // }

    ~IntPointeClass() { delete this->value; };
};

class IntpointerClass2
{
private:
    int *pvalue;

public:
    IntpointerClass2(const int &obj) : pvalue(new int(obj)) {};
    IntpointerClass2(const IntpointerClass2 &obj) : pvalue(new int(*obj.pvalue)) {};         // copy constructor
    IntpointerClass2(IntpointerClass2 &&obj) : pvalue(obj.pvalue) { obj.pvalue = nullptr; }; // move constructor

    IntpointerClass2 &operator=(const IntpointerClass2 &obj);
    IntpointerClass2 &operator=(IntpointerClass2 &&obj);

    void print() const { cout << "ipc2 " << *pvalue << endl; }
    int read() const { return *pvalue; };
    void write(const int &obj);

    ~IntpointerClass2() { delete pvalue; };
};

IntpointerClass2 &IntpointerClass2::operator=(const IntpointerClass2 &obj) // copy assignment
{
    if (this != &obj)
    {
        *pvalue = *obj.pvalue;
    }

    return *this;
}

IntpointerClass2 &IntpointerClass2::operator=(IntpointerClass2 &&obj)
{
    std::swap(pvalue, obj.pvalue);
    return *this;
}

void IntpointerClass2::write(const int &obj)
{
    int tmp = obj;
    *pvalue = tmp;
}

int main(int argc, char const *argv[])
{
    {
        IntPointeClass ipc(5);
        ipc.print();

        int num(6);
        ipc.write(num);
        num = 7;
        ipc.print();
        cout << "num" << num << endl;
        ipc.print();
    };

    cout << "---------------------" << endl;

    int num(5);
    IntpointerClass2 ipc2_(num);
    ipc2_.print();
    IntpointerClass2 ipc2(6);
    ipc2.print();

    return 0;
}
