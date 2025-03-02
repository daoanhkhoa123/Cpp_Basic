#include<iostream>

void func()
{
    (7 == 5);   // evaluates to false
    (5 > 4);   // evaluates to true
    (3 != 2);    // evaluates to true
    (6 >= 6);  // evaluates to true
    (5 < 5);  // evaluates to false 

    int a, b, c;
    (a == 5);    // evaluates to false, since a is not equal to 5
    (a * b >= c);  // evaluates to true, since (2*3 >= 6) is true
    (b + 4 > a * c);  // evaluates to false, since (3+4 > 2*6) is false
    ((b = 2) == a); // evaluates to true 

    !(5 == 5);   // evaluates to false because the expression at its right (5 == 5) is true
    !(6 <= 4);  // evaluates to true because (6 <= 4) would be false
    !true;    // evaluates to false
    !false;   // evaluates to true 

    ((5 == 5) && (3 > 6)); // evaluates to false ( true && false )
    ((5 == 5) || (3 > 6)); // evaluates to true ( true || false ) 

    int i, n;
    if ((i < 10) && (++i < n)) { /*...*/ }; // note that the condition increments i 

    bool condition;
    condition ? true : false;

    7 == 5 ? 4 : 3;    // evaluates to 3, since 7 is not equal to 5.
    7 == 5 + 2 ? 4 : 3;  // evaluates to 4, since 7 is equal to 5+2.
    5 > 3 ? a : b;   // evaluates to the value of a, since 5 is greater than 3.
    a > b ? a : b;  // evaluates to whichever is greater, a or b.  

}

int main()
{
    int a, b;
    a = 10;
    b = 4;
    a = b;
    b = 7;

    std::cout << "a:";
    std::cout << a << std::endl;
    std::cout << "b" << b;

    a += b;
    std::cout << "a:" << a << std::endl;

    ++a; a++;

    int i;
    float f = 3.14;
    i = (int)f;

    int x = sizeof(char);
    x = sizeof(i);

    x = 5 + 7 % 2;
    x == 5 + (7 % 2);
    x != (5 + 7) % 2;


    return 0;
}