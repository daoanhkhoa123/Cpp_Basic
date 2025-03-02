// template <typename Container>
// void removeEveryOtherItem(Container &list)
// {
//     Container::iterator itr = list.begin()

//     while(itr != lst.end())
//     {
//         itr = list.erase(itr)
//         if(itr != lst.end())
//         {
//             ++itr;
//         }
//     }
// }

template <typename Container, typename Comparable>
void change(Container &cont, const Comparable &obj)
{
    typename Container::iterator itr = c.begin();
    while (itr != c.end())
    {
        *itr++ = obj;
    }
}