//overloaded operators for vectors described in class
#include <iostream>
#include <vector>

using namespace std;

class size_must_match
{
};

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    size_t s{v.size() - 1};
    out << "(";
    for (size_t i{0}; i < s; i++)
        out << v[i] << ", ";
    out << v[s] << ")\n";
    return out;
}

template <typename T>
vector<T> operator+(const vector<T> &v, const vector<T> &w)
{
    size_t s{v.size()};
    if (s != w.size())
        throw size_must_match{};
    vector<T> u(s);
    for (size_t i{0}; i < s; i++)
        u[i] = v[i] + w[i];
    return u;
}

template <typename T>
vector<T> operator+=(vector<T> &v, const vector<T> &w)
{
    v = v + w;
    return v;
}

template <typename T>
vector<T> operator-(const vector<T> &v)
{
    size_t s{v.size()};
    vector<T> u(s);
    for (size_t i{0}; i < s; i++)
        u[i] = -v[i];
    return u;
}

template <typename T>
vector<T> operator-(const vector<T> &v, const vector<T> &w)
{
    size_t s{v.size()};
    if (s != w.size())
        throw size_must_match{};
    vector<T> u(s);
    for (size_t i{0}; i < s; i++)
        u[i] = v[i] - w[i];
    return u;
}

template <typename T>
vector<T> operator-=(vector<T> &v, const vector<T> &w)
{
    v = v - w;
    return v;
}

template <typename T>
T operator*(const vector<T> &v, const vector<T> &w)
{
    size_t s{v.size()};
    if (s != w.size())
        throw size_must_match{};
    T p{0};
    for (size_t i{0}; i < s; i++)
        p += v[i] * w[i];
    return p;
}

//make sure to use scalars as 1.0/1.0L if the vectors are of type double and long double
template <typename T>
vector<T> operator*(const T &x, const vector<T> &v)
{
    size_t s{v.size()};
    vector<T> u(s);
    for (size_t i{0}; i < s; i++)
        u[i] = x * v[i];
    return u;
}

template <typename T>
vector<T> operator*(const vector<T> &v, const T &x)
{
    return x * v;
}