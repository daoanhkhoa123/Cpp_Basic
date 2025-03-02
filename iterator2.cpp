template <typename Container>
auto begin(Container &c) -> decltype(c.begin())
{
    return c.begin();
}

template <typename Container>
auto begin(const Container &c) -> decltype(c.begin())
{
    return c.begin();
}