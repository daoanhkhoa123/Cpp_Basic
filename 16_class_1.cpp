#include <iostream>
using namespace std;

class Rectangle_cpp
{
    int width, height;

public:
    void set_values(int, int);
    int area() { return width * height; };
};

void Rectangle_cpp::set_values(int x, int height)
{
    width = x;
    this->height = height; // in case same variable name
}

class Rectangle
{
private:
    int width, height;

public:
    Rectangle(); // default init
    Rectangle(int, int);
    ~Rectangle();

    int area();
};

int width_transformer(int width) { return width * 2; };
int height_transformer(int height) { return height * 2; };

// default init
Rectangle::Rectangle() : width(5), height(5)
{
    std::cout << "Rectangle default created" << std::endl;
}

// init with params
Rectangle::Rectangle(int width, int height) : width(width_transformer(width)), height(height_transformer(height))
{

    std::cout << "Rectangle created" << std::endl;
}

Rectangle::~Rectangle()
{
    std::cout << "Rectangle destroyed" << std::endl;
}

int Rectangle::area() { return width * this->height; }

int main(int argc, char const *argv[])
{
    {
        Rectangle_cpp rect;
        rect.set_values(3, 4);
        std::cout << "area: " << rect.area() << std::endl;
    }

    {
        Rectangle rect(3, 4);
        Rectangle sqr;                                     // default
        std::cout << "area: " << rect.area() << std::endl; // should be 48
        std::cout << "area: " << sqr.area() << std::endl;
    }

    return 0;
}
