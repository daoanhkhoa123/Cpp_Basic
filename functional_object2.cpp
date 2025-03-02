#include <iostream>
#include <vector>

using namespace std;

class Rectangle
{
private:
    float width, height;

public:
    Rectangle(float width = 0, float height = 0) : width(width), height(height) {};

    const float &get_width() const { return width; };
    const float &get_height() const { return height; };

    float area() const { return width * height; };
    bool operator<(const Rectangle &obj) const;
};

bool Rectangle ::operator<(const Rectangle &obj) const
{
    return area() < obj.area();
}

ostream &operator<<(ostream &out, const Rectangle &obj)
{
    return out << obj.area();
}

template <typename Comparable, typename Comparator>
const Comparable &findMax(const vector<Comparable> &arr, const Comparator &&comp)
{
    int maxInt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (comp(arr[maxInt], arr[i]))
        {
            maxInt = i;
        }
    }

    return arr[maxInt];
}

template <typename Comparable>
const Comparable &findMax(const vector<Comparable> &arr)
{
    return findMax(arr, less<Comparable>{});
}

class WidthCompareRectangle
{
public:
    bool operator()(const Rectangle &lhs, const Rectangle &rhs) const { return (lhs.get_width() < rhs.get_width()); };
};

int main(int argc, char const *argv[])
{
    vector<Rectangle> vec{Rectangle(3, 4), Rectangle(1, 100), Rectangle(100, 2)};

    Rectangle rec_max_area = findMax(vec);
    Rectangle rec_max_width = findMax(vec, WidthCompareRectangle{});

    cout << rec_max_area;
    cout << rec_max_width;

    return 0;
}
