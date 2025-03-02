#include <vector>
using namespace std;

template <typename Comparable>
class matrix
{
private:
    vector<vector<Comparable>> ndarray;

public:
    matrix(const int nrows = 1, const int ncols = 0);
    matrix(const vector<vector<Comparable>> v) : ndarray(v) {};
    matrix(const vector<vector<Comparable>> &&v) : ndarray(std::move(v)) {};

    vector<Comparable> &operator[](const int row);
    const vector<Comparable> &operator[](const int row) const;

    int num_rows() const { return ndarray.size(); };
    int num_cols() const { return num_rows() ? ndarray[0].size() : 0; };
};

template <typename Comparable>
matrix<Comparable>::matrix(const int nrows, const int ncols) : ndarray(nrows)
{
    for (vector<Comparable> &row : ndarray)
    {
        row.resize(ncols);
    }
}

template <typename Comparable>
vector<Comparable> &matrix<Comparable>::operator[](const int row)
{
    return ndarray[row];
}

template <typename Comparable>
const vector<Comparable> &matrix<Comparable>::operator[](const int row) const
{
    return ndarray[row];
}

int main(int argc, char const *argv[])
{
    matrix<int> mat(4, 5);
    mat[2];
    return 0;
}
