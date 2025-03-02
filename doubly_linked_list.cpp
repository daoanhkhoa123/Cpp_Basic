#include <iostream>
#include <utility>
#include <algorithm>

template <typename Comparable>
class DoublyLinkedList
{

private:
    struct Node;
    Node *pstart, *pend;

public:
    class const_Iterator;
    class Iterator;

    const const_Iterator begin_start() const;
    const const_Iterator end_end() const;
    const const_Iterator begin_end() const;
    const const_Iterator end_start() const;

    explicit DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<Comparable> &obj);
    DoublyLinkedList(DoublyLinkedList<Comparable> &&obj);

    Node *head() { return pstart->next; };

    bool is_empty() { return pstart->next == pend; };

    void append(const Comparable &obj);
    void append(Comparable &&obj);

    void pop();

    DoublyLinkedList<Comparable> &operator=(const DoublyLinkedList<Comparable> &obj);
    DoublyLinkedList<Comparable> &operator=(DoublyLinkedList<Comparable> &&obj);
};

template <typename Comparable>
struct DoublyLinkedList<Comparable>::Node
{
    Comparable data;
    Node *next, *prev;
};

template <typename Comparable>
class DoublyLinkedList<Comparable>::const_Iterator
{
    friend class DoublyLinkedList<Comparable>;

private:
    Node *pobj;

public:
    explicit const_Iterator(Node *pobj) : pobj(pobj) {};
    const_Iterator(const const_Iterator &obj) : pobj(obj.pobj) {};

    const Comparable &get() const { return pobj->data; };
    Comparable &get() { return pobj->data; };
    void set(const Comparable &obj) { pobj->data = obj; };
    void set(Comparable &&obj) { pobj->data = std::move(obj); };

    const_Iterator &operator++();
    const_Iterator operator++(int);
    const_Iterator &operator--();
    const_Iterator operator--(int);

    const_Iterator &operator=(const const_Iterator &obj);
    const_Iterator &operator=(const_Iterator &&obj);

    friend std::ostream &operator<<(std::ostream &out, const const_Iterator &obj)
    {
        out << obj.pobj->data;
        return out;
    };
    bool operator!=(const const_Iterator &obj) { return pobj != obj.pobj; }

    const Comparable &operator*() const { return *pobj; }
    Comparable &operator*() { return *pobj; }
};

template <typename Comparable>
DoublyLinkedList<Comparable>::DoublyLinkedList()
{
    pstart = new Node;
    pstart->next = pend;
    pstart->prev = nullptr;

    pend = new Node;
    pend->prev = pstart;
    pend->next = nullptr;
};

template <typename Comparable>
DoublyLinkedList<Comparable>::DoublyLinkedList(const DoublyLinkedList<Comparable> &obj) : DoublyLinkedList()
{
    for (DoublyLinkedList<Comparable>::const_Iterator i = obj.begin_start(); i != obj.end_end(); ++i)
    {
        append(i.get());
    }
}

template <typename Comparable>
DoublyLinkedList<Comparable>::DoublyLinkedList(DoublyLinkedList<Comparable> &&obj) : pstart(obj.pstart), pend(obj.pend)
{
    while (!obj.is_empty())
        obj.pop();

    obj.pstart = nullptr;
    obj.pend = nullptr;
}

template <typename Comparable>
void DoublyLinkedList<Comparable>::append(const Comparable &obj)
{
    Node *node = new Node;
    node->data = obj;
    node->next = pend;
    node->prev = pend->prev;

    pend->prev->next = node;
    pend->prev = node;
};

template <typename Comparable>
void DoublyLinkedList<Comparable>::append(Comparable &&obj)
{
    Node *node = new Node;
    node->data = std::move(obj);
    node->next = pend;
    node->prev = pend->prev;

    node->prev->next = node;
    pend->prev = node;
};

template <typename Comparable>
void DoublyLinkedList<Comparable>::pop()
{
    if (is_empty())
        return;

    Node *pre = pend->prev->prev;
    Node *nex = pre->next->next;
    pre->next = nex;
    nex->prev = pre;

    delete pre->next;
}

template <typename Comparable>
const typename DoublyLinkedList<Comparable>::const_Iterator DoublyLinkedList<Comparable>::begin_start() const
{
    return const_Iterator(pstart->next);
}

template <typename Comparable>
const typename DoublyLinkedList<Comparable>::const_Iterator DoublyLinkedList<Comparable>::end_end() const
{
    return const_Iterator(pend);
}

template <typename Comparable>
const typename DoublyLinkedList<Comparable>::const_Iterator DoublyLinkedList<Comparable>::begin_end() const
{
    return const_Iterator(pend->prev);
}

template <typename Comparable>
const typename DoublyLinkedList<Comparable>::const_Iterator DoublyLinkedList<Comparable>::end_start() const
{
    return const_Iterator(pstart);
}

template <typename Comparable>
DoublyLinkedList<Comparable> &DoublyLinkedList<Comparable>::operator=(const DoublyLinkedList<Comparable> &obj)
{
    DoublyLinkedList copy = obj;
    std::swap(*this, copy);
    return *this;
}

template <typename Comparable>
DoublyLinkedList<Comparable> &DoublyLinkedList<Comparable>::operator=(DoublyLinkedList<Comparable> &&obj)
{
    std::swap(pstart, obj.pstart);
    std::swap(pend, obj.pend);

    return *this;
}

template <typename Comparable>
typename DoublyLinkedList<Comparable>::const_Iterator &DoublyLinkedList<Comparable>::const_Iterator::operator++()
{
    pobj = pobj->next;
    return *this;
}

template <typename Comparable>
typename DoublyLinkedList<Comparable>::const_Iterator DoublyLinkedList<Comparable>::const_Iterator::operator++(int)
{
    const_Iterator result = *this;
    pobj = pobj->next;

    return result;
}

template <typename Comparable>
typename DoublyLinkedList<Comparable>::const_Iterator &DoublyLinkedList<Comparable>::const_Iterator::operator--()
{
    pobj = pobj->prev;
    return *this;
}

template <typename Comparable>
typename DoublyLinkedList<Comparable>::const_Iterator DoublyLinkedList<Comparable>::const_Iterator::operator--(int)
{
    const_Iterator result = *this;
    pobj = pobj->prev;

    return result;
}

template <typename Comparable>
typename DoublyLinkedList<Comparable>::const_Iterator &DoublyLinkedList<Comparable>::const_Iterator::operator=(const const_Iterator &obj)
{
    pobj = obj.pobj;
    return *this;
}

template <typename Comparable>
typename DoublyLinkedList<Comparable>::const_Iterator &DoublyLinkedList<Comparable>::const_Iterator::operator=(const_Iterator &&obj)
{
    pobj = std::move(obj.pobj);
    return *this;
}

int main(int argc, char const *argv[])
{
    DoublyLinkedList<int> dll;

    for (int i = 0; i < 10; i++)
    {
        dll.append(i);
    }

    DoublyLinkedList<int> dll2(dll);

    for (int i = 0; i < 5; i++)
    {
        dll2.pop();
    }

    DoublyLinkedList<int> dll3 = dll2;

    for (DoublyLinkedList<int>::const_Iterator i = dll3.begin_start(); i != dll3.end_end(); ++i)
    {
        std::cout << i << std::endl;

        if (i.get() % 2 == 0)
        {
            i.set(69420);
        }
    }

    std::cout << "1------" << std::endl;
    for (DoublyLinkedList<int>::const_Iterator i = dll.begin_end(); i != dll.end_start(); i--)
    {
        std::cout << i << std::endl;
    }
    std::cout << "2------" << std::endl;
    for (DoublyLinkedList<int>::const_Iterator i = dll2.begin_end(); i != dll2.end_start(); i--)
    {
        std::cout << i << std::endl;
    }

    std::cout << "3------" << std::endl;
    for (DoublyLinkedList<int>::const_Iterator i = dll3.begin_end(); i != dll3.end_start(); i--)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
