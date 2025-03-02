#include<iostream>
#include<string>

#define PI 3.14159
#define NEWLINE '\n'

bool var1 = true;
bool var2 = false;
int* p = nullptr;

const double pi = 3.1415927;
const char tab = '\t';

void type()
{
    75; // int
    75u; // unsigned int
    75l; // long
    75ul; //unsigned long
    75lu; //unsigned long

    3.14159;//3.14159
    6.02e23;//6.02 * 10 ** 23
    1.6e-19; //1.6 * 19 **-19
    3.0; // 3.0

    3.14159L; // long double
    6.02e23f; //float

    'z'; 'p';
    "Hello World"; "How do you do?";

    '\n'; "\t";
    "Left \t Right";
    "one\ntwo\nthree";

    "this forms" "a single"     "  string  "    "of characters"
        == "this formsa single string of characters";

    std::string x = "string expressed in \
    two lines";
    x == "string expressed in two lines"; // true

    R"(string with \backslash)" == "string with \\backslash"; // true
    // R"&%$(string with \backslash)&%$" == "string with \\backslash";  //true


}

int main()
{
    double r = 5;
    double circle = 2 * pi * r;

    std::cout << circle << NEWLINE;
}