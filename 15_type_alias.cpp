#include <iostream>

typedef unsigned int WORD;
typedef char *pChar;
typedef char field[50];
using small_field = char[50];

union mix_t
{
    int l;

    struct
    {
        short hi;
        short lo;
    } s;

    char c[4];
};

union vector3D_t
{
    float x, y, z;
    float vector[3];
} v;

enum months_t
{
    january = 0,
    february,
    march,
    april,
    may,
    june,
    july,
    august,
    september,
    october,
    november,
    december
} y2k;

enum class Colors // enum struct
{
    black,
    blue,
    green,
    cyan,
    red
};

int main(int argc, char const *argv[])
{
    v.x = 6;
    v.y = 7;
    v.z = 8;

    for (int i = 0; i < 3; i++)
    {
        std::cout << v.vector[i] << " ";
    }
    std::cout << "\n ";

    Colors color;
    color = Colors::blue;
    if (color == Colors::green)
    {
        color = Colors::red;
    }

    return 0;
}
