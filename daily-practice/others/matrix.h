#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <string>

template<class T> class matrix;

template<typename T>
class proxy_matrix
{
private:
    matrix<T> *mptr;
    int row;
public:
    proxy_matrix(matrix<T> *m, int i) : mptr(m), row(i) {}
    T& operator[](int i)
    {
        return mptr->at(row, i);
    }
};

template<typename T>
class const_proxy_matrix
{
private:
    const matrix<T> *mptr;
    int row;
public:
    const_proxy_matrix(const matrix<T> *m, int i) : mptr(m), row(i) {}
    T operator[](int i)
    {
        return mptr->at(row, i);
    }
};

struct matrixError
{
    const std::string reason;
    matrixError(std::string r) :reason(r) {}
};

struct indexError : public matrixError, public std::out_of_range
{
    int index;

    indexError(int i, const char *r = "Bad index") : matrixError(r), out_of_range(r), index(i)
    {}

    const char *what() const throw()
    {
        std::ostringstream os;
        os << std::out_of_range::what();
        os << ", index = " << index;
        return os.str().c_str();
    }

    virtual ~indexError() throw()
    {}
};

struct rowIndexError : public indexError
{
    rowIndexError(int i) : indexError(i, "Bad row index") {}
};

struct colIndexError : public indexError
{
    colIndexError(int i) : indexError(i, "Bad col index") {}
};

template <typename T>
class matrix
{
private:
    int x;
    int y;
    T *v;
    void copy(const matrix &other);
    void check(int, int) const throw(indexError);
public:
    matrix() : x(0), y(0), v(0) {}
    matrix(int, int);
    matrix(const matrix&);
    ~matrix();

    matrix operator=(const matrix&);

    int rows() const { return x; }
    int cols() const { return y; }

    T& at(int, int) throw(indexError);
    T at(int, int) const throw(indexError);
    T& operator()(int, int);
    T operator()(int, int) const;

    matrix operator+=(const matrix&);

    proxy_matrix<T> operator[](int i)
    {
        return proxy_matrix<T>(this, i);
    }

    const_proxy_matrix<T> operator[](int i) const
    {
        return const_proxy_matrix<T>(this, i);
    }
};

template<typename T>
matrix<T>::matrix(int i, int j) : x(i), y(j)
{
    v = new T[i * j];
}

template<typename T>
matrix<T>::matrix(const matrix &other)
{
    copy(other);
}

template<typename T>
matrix<T>::~matrix()
{
    delete[] v;
    v = 0;
}

template<typename T>
matrix<T> matrix<T>::operator=(const matrix &other)
{
    if(this == &other)
    {
        return *this;
    }

    const int oldx = x;
    const int oldy = y;
    const T *oldv = v;

    try
    {
        copy(other);
        delete[] oldv;
        oldv = 0;
    }
    catch(...)
    {
        x = oldx;
        y = oldy;
        delete[] v;
        v = oldv;
        throw;
    }

    return *this;
}

template<typename T>
void matrix<T>::copy(const matrix &other)
{
    x = other.x;
    y = other.y;

    if(v)
    {
        delete[] v;
        v = 0;
    }
    v = new T[x * y];
    memcpy(v, other.v, sizeof(T) * x * y);
}

template<typename T>
void matrix<T>::check(int i, int j) const throw (indexError)
{
    if(i < 0 || i >= x)
    {
        throw rowIndexError(i);
    }
    if(j < 0 || j >= y)
    {
        throw colIndexError(j);
    }
}

template<typename T>
T& matrix<T>::at(int i, int j) throw(indexError)
{
    check(i, j);
    return operator()(i, j);
}

template<typename T>
T matrix<T>::at(int i, int j) const throw(indexError)
{
    check(i, j);
    return operator()(i, j);
}

template<typename T>
T& matrix<T>::operator()(int i, int j)
{
    return v[i * y + j];
}

template<typename T>
T matrix<T>::operator()(int i, int j) const
{
    return v[i * y + j];
}

template<typename T>
matrix<T> matrix<T>::operator+=(const matrix &other)
{
    for(int i = 0; i < x * y; ++i)
    {
        v[i] += other.v[i];
    }
    return *this;
}

template<typename T>
matrix<T> operator+(const matrix<T> &left, const matrix<T> &right)
{
    matrix<T> temp(left);
    temp += right;

    return temp;
}

#endif