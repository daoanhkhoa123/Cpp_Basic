#include <iostream>
#include "head1.h"
using namespace std;

int main(int argc, char const *argv[])
{
    IntCell num;

    num.write(5);
    cout << num.read() << endl;

    IntCell *m;

    m = new IntCell;
    m->write(5);
    cout << m->read() << endl;
    delete m;

    return 0;
}

