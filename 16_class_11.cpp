#include <iostream>

float const PI = 3.14;

class Circle
{
private:
    float radius;

public:
    Circle(float radius);
    Circle();
    ~Circle();

    float area();
};

Circle::Circle() : radius(1)
{
    std::cout << "Circle default created" << std::endl;
};

Circle::Circle(float radius) : radius(radius)
{
    if (radius < 0)
    {
        std::cout << "Error" << std::endl;
        return;
    }

    std::cout << "Circle created" << std::endl;
}

Circle::~Circle()
{
    std::cout << "Circle destroyed" << std::endl;
}

float Circle::area()
{
    return this->radius * this->radius * PI;
}

class Cylinder
{
private:
    float height;
    Circle circle;

public:
    Cylinder(float radius, float height);
    ~Cylinder();

    float volume();
};

Cylinder::Cylinder(float radius, float height) : circle(radius), height(height)
{
    std::cout << "Cylinder created" << std::endl;
}

Cylinder::~Cylinder()
{
    std::cout << "Cylinder destroyed" << std::endl;
}

float Cylinder::volume()
{
    return this->circle.area() * this->height;
}

int main(int argc, char const *argv[])
{
    Circle circle(5);
    std::cout << circle.area() << std::endl;

    Cylinder cylinder(5, 6);
    std::cout << cylinder.volume() / circle.area() << std::endl;


    return 0;
}
