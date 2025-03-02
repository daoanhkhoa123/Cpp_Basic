#include<iostream>
#include<string>

int main()
{
    // c like init
    int a = 5;

    // c++ construct init
    int b(2);

    a = a + 1;

    // c++ unifrom init
    int result{ a - b };

    std::cout << result;


    // type deduction
    int var1 = 0;
    auto var2 = var1; // int var2 = var1
    decltype(var1) var3 = 0; // int var2

    var2 = var2 + 1;
    var3 = var3 - var1;

    // string
    std::string str = "This is a string";
    std::cout << str << std::endl;
    std::string str1 = "This is a string";
    std::cout << str << std::endl;
    std::string str2("This is another string");
    std::cout << str << std::endl;
    std::string str3{ "This is another another string" };
    std::cout << str << std::endl;

    return 0;
}