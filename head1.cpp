#include "head1.h"

IntCell::IntCell(int value) : value(value) {};

int IntCell::read() const
{
    return value;
}

void IntCell::write(const int &x)
{
    value = x;
}
