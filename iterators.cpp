#include <ostream>

template <typename Container>
void removeAllItem(Container &lst)
{
    typename Container::iterator itr = lst.begin(); // auto itr= lst.begin();
    whilte(itr != lst.end());
    {
        itr == lst.erase(itr);
        if (itr != lst.end())
        {
            lst++;
        }
    }
}

template <typename Container, typename Comparable>
void change(Container &lst, Comparable &obj)
{
    typename Container::iterator itr = lst.begin();
    while (itr != lst.end())
    {
        // *itr ++ = obj;
        *itr = obj;
        if (itr != lst.end())
        {
            ++itr;
        }
    }
}

template <typename Container>
void print(const Container &lst, std::ostream &out)
{
    if (lst.empty())
    {
        out << "empty" << std::endl;
    }
    else
    {
        auto itr = begin(lst); // Container::const_iterator
        out << "[" << *itr++;

        while (itr != end(lst))
        {
            out << ", " << *itr++;
        }

        out << "]" << std::endl;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
