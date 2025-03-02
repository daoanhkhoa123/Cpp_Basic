#include <utility>

template <typename Comparable>
class Vector
{
private:
    Comparable *pobj = nullptr;
    int size;
    int capacity;

public:
    static const int SPARE_CAPACITY = 16;

    explicit Vector(int capacity);
    Vector(const Vector<Comparable> &rhs);
    Vector(Vector<Comparable> &&rhs);

    Vector &operator=(const Vector &rhs);
    Vector &operator=(Vector &&rhs);

    Comparable &operator[](const int i);
    const Comparable &operator[](const int i) const;

    void recapacity(int new_capacity);
    void resize(int new_size);

    bool is_empty() const { return size == 0; };
    int get_size() const { return size; };
    int get_capacity() const { return capacity; };

    void append(const Comparable &obj);
    void append(Comparable &&obj);

    void pop_back() { size--; };
    const Comparable &back() const { return pobj[size - 1]; };

    typedef Comparable *iterator;
    typedef const Comparable *const_iterator;

    iterator begin();
    const iterator begin() const;
    iterator end();
    const_iterator end() const; // to demo the usage

    ~Vector() { delete[] pobj; };
};

template <typename Comparable>
Vector<Comparable>::Vector(int size) : size(size), capacity(size + SPARE_CAPACITY) { pobj = new Comparable[capacity]; };

template <typename Comparable>
Vector<Comparable>::Vector(const Vector<Comparable> &rhs) : size(size), capacity(capacity), pobj(new Comparable[size])
{
    for (int i = 0; i < size; ++i)
    {
        pobj[i] = rhs.pobj[i];
    }
}

template <typename Comparable>
Vector<Comparable> &Vector<Comparable>::operator=(const Vector &rhs)
{
    // delete[] pobj;
    // pobj = nullptr;
    // pobj = new Object[capacity];

    // capacity = rhs.capacity;
    // size = rhs.size;

    // for (int i = 0; i < size; ++i)
    // {
    //     pobj[i] = rhs.pobj[i];
    // }

    Vector copy = rhs;
    std::swap(*this, copy);
    return *this;

    return *this;
}

template <typename Comparable>
Vector<Comparable>::Vector(Vector<Comparable> &&rhs) : size(rhs.size), capacity(rhs.capacity), pobj(rhs.pobj)
{
    rhs.pobj = nullptr;
    rhs.capacity = 0;
    rhs.size = 0;
}

template <typename Comparable>
Vector<Comparable> &Vector<Comparable>::operator=(Vector &&rhs)
{
    // this = std::move(rhs); // 1

    // delete[] pobj; // 2
    // pobj = nullptr;
    // pobj = std::move(rhs.pobj);

    // size = std::move(rhs.size);
    // capacity = std::move(rhs.capacity);

    std::swap(size, rhs.size);
    std::swap(capacity, rhs.capacity);
    std::swap(pobj, rhs.pobj);

    return *this;
}

template <typename Comparable>
Comparable &Vector<Comparable>::operator[](const int i)
{
    return pobj[i];
}

template <typename Comparable>
const Comparable &Vector<Comparable>::operator[](const int i) const
{
    return pobj[i];
}

template <typename Comparable>
void Vector<Comparable>::recapacity(int new_capacity)
{
    if (new_capacity < capacity)
        return;

    capacity = new_capacity;

    Comparable *arr = new Comparable[new_capacity];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = std::move(pobj[i]);
    }

    delete[] pobj;
    // pobj = arr;
    std::swap(pobj, arr);
}

template <typename Comparable>
void Vector<Comparable>::resize(int new_size)
{
    if (new_size > capacity)
        recapacity(capacity * 2);

    size = new_size;
}

template <typename Comparable>
void Vector<Comparable>::append(const Comparable &obj)
{
    if (size == capacity)
        resize(++size); // recapacity(capacity * 2 +1 )

    pobj[size++] = obj;
}

template <typename Comparable>
void Vector<Comparable>::append(Comparable &&obj)
{
    if (size == capacity)
        resize(++size); // recapacity(capacity * 2 +1 )

    pobj[++size] = std::move(obj);
}

template <typename Comparable>
typename Vector<Comparable>::iterator Vector<Comparable>::begin()
{
    return &pobj[0];
}

template <typename Comparable>
const typename Vector<Comparable>::iterator Vector<Comparable>::begin() const
{
    return &pobj[0];
}

template <typename Comparable>
typename Vector<Comparable>::iterator Vector<Comparable>::end()
{
    return &pobj[size];
}

template <typename Comparable>
typename Vector<Comparable>::const_iterator Vector<Comparable>::end() const // to demo usage
{
    return &pobj[size];
}

int main(int argc, char const *argv[])
{
    Vector<int> v(10);

    return 0;
}
