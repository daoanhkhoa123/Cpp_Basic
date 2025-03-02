#include <ios

template <typename Comparable>
struct TreeNode
{
    Comparable data;
    TreeNode *left;
    TreeNode *right;

    const Comparable &findMax() const;
    const Comparable &findMin() const;

    bool contains(const Comparable &x) const;
    bool isEmpty() const;

    void print()
};
