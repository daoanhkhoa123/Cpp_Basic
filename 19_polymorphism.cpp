#include <iostream>
using namespace std;

class Polygon
{
protected:
    int width = 1, height = 1;

public:
    Polygon() {};
    Polygon(int width, int height) : width(width), height(height) {};

    void set_values(int a, int b)
    {
        width = a;
        height = b;
    };

    // virtual int area() { return 0; }
    virtual int area() = 0;

    void print()
    {
        cout << this->area() << endl;
    }
};

class Rectangle : public Polygon
{
public:
    Rectangle() {};
    Rectangle(int width, int height) : Polygon(width, height) {};

    int area()
    {
        return width * height;
    }
};

class Triangle : public Polygon
{
public:
    Triangle() {};
    Triangle(int width, int height) : Polygon(width, height) {};

    int area()
    {
        return width * height / 2;
    };
};

int main(int argc, char const *argv[])
{
    Rectangle rect;
    Triangle triangle;
    // Polygon poly;

    Polygon *prect = &rect;
    Polygon *ptriangle = &triangle;
    // Polygon *ppoly = &poly;

    // rect.set_values(4,5);
    prect->set_values(4, 5);
    ptriangle->set_values(4, 5);
    // ppoly->set_values(4, 5);

    // cout << rect.area() << endl;
    // cout << triangle.area() << endl;
    // cout << ppoly->area() << endl;

    prect->print();
    ptriangle->print();

    Polygon *prect2 = new Rectangle(4, 5);
    Polygon *ptriangle2 = new Triangle(4, 5);

    prect2->print();
    cout << prect->area() << endl;
    ptriangle2->print();

    delete prect2;
    delete ptriangle2;

    return 0;
}
