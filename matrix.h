#ifndef MATRIX_H
#define MATRIX_H

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
    matrix(const vector<vector<Comparable>> v &&) : ndarray(std::move(v))

                                                        ~matrix();
};

template <typename Comparable>
matrix<Comparable>::matrix(const int nrows = 1, const int ncols = 0) : ndarray(nrows)
{
    for (vector<Comparable> &row : ndarray)
    {
        row.resize(ncols);
    }
}

#endif