#include <iostream>
using namespace std;

class Polygon
{
protected:
    int width, height;

public:
    Polygon(int width, int height) : width(width), height(height) {};
};

class Output
{
public:
    static void print(int i);
};

void Output::print(int i)
{
    cout << i << endl;
}

class Rectangle : public Polygon, public Output
{
public:
    Rectangle(int width, int height) : Polygon(width, height) {};
    int area() { return width * height; };
};

class Triangle : public Polygon, public Output
{
public:
    Triangle(int width, int height) : Polygon(width, height) {};
    int area();
};
int Triangle::area() { return width * height / 2; }

int main(int argc, char const *argv[])
{
    Rectangle rect(4, 5);
    Triangle triangle(4, 5);

    cout << rect.area() << endl;
    cout << triangle.area() << endl;

    return 0;
}

/*

class Mother {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
};

class Daughter : protected Mother {
    // publicVar is now protected
    // protectedVar remains protected
    // privateVar remains private
};


*/