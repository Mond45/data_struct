#include <vector>
#include <unordered_set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T> &A, const vector<T> &B)
{
    vector<T> v(A.begin(), A.end());
    unordered_set<T> sa;
    for (auto &&e : A)
    {
        sa.emplace(e);
    }
    for (auto &&e : B)
    {
        if (sa.find(e) == sa.end())
        {
            v.emplace_back(e);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T> &A, const vector<T> &B)
{
    vector<T> v;
    unordered_set<T> sb;
    for (auto &&e : B)
    {
        sb.emplace(e);
    }
    for (auto &&e : A)
    {
        if (sb.find(e) != sb.end())
        {
            v.emplace_back(e);
        }
    }
    return v;
}
