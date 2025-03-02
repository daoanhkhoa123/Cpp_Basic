#include <iostream>
#include <vector>
using namespace std;

template <typename Comparable>
const Comparable &findMax(const vector<Comparable> &a)
{
    int maxInt = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (!(a[i] < a[maxInt]))
        {
            maxInt = i;
        }
    }

    return a[maxInt];
}

class Square
{
private:
    float edge;

public:
    explicit Square(const float &init_edge = 0) : edge(init_edge) {};

    float get_side() const { return edge; };
    float perimiter() const { return edge * 4; };
    float area() const { return edge * edge; };

    Square &operator=(const Square &obj);
    bool operator<(const Square &obj) const { return get_side() < obj.get_side(); };
    void print(ostream &os = cout) const { os << get_side() << endl; };

    ~Square() {};
};

Square &Square::operator=(const Square &obj)
{
    edge = obj.edge;
    return *this;
}

ostream &operator<<(ostream &os, const Square &obj)
{
    obj.print(os);
    // os << obj.get_side() << endl;
    return os;
}

int main(int argc, char const *argv[])
{
    vector<Square> v = {Square(5), Square(6), Square(4)};

    cout << "Largest side: " << findMax(v) << endl;

    return 0;
}
