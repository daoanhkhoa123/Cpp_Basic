#include <iostream>
#include <string>
#include <sstream>

struct movie_t
{
    std::string title;
    int year;
};

void movie_print(movie_t movie);

int main(int argc, char const *argv[])
{
    std::string str;
    movie_t amovie;
    movie_t *pmovie = &amovie;

    std::cout << "Enter title: ";
    getline(std::cin, pmovie->title);
    std::cout << "Enter year: ";
    getline(std::cin, str);
    (std::stringstream) str >> pmovie->year;

    std::cout << "\nYou have entered:\n";
    std::cout << pmovie->title;
    std::cout << " (" << pmovie->year << ")\n";

    return 0;
}
