#include <iostream>
using namespace std;

class Vector
{
private:
public:
    float x, y;
    Vector(float x, float y);
    ~Vector();

    Vector operator+(const Vector &);
    Vector &operator=(const Vector &);
    bool is(const Vector &);
    // ostream &operator<<(ostream &os); // overload ostream, not Vector
};

Vector::Vector(float x, float y) : x(x), y(y) {};
Vector::~Vector() {};

Vector Vector::operator+(const Vector &obj)
{
    return Vector(this->x + obj.x, this->y + obj.y);
}

Vector &Vector::operator=(const Vector &obj)
{
    x = obj.x;
    y = obj.y;
    return *this;
}

bool Vector::is(const Vector &obj)
{
    if (&obj == this)
        return true;
    else
        return false;
}

ostream &operator<<(ostream &os, const Vector &obj)
{
    os << obj.x << ", " << obj.y;
    return os;
}

int main(int argc, char const *argv[])
{
    Vector v(3, 1);
    Vector u(1, 2);
    u = v;
    cout << v + u << endl;
}
