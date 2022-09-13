#include <vector>
#include <iostream>

using namespace std;

template <typename T>
bool is_reverse(const vector<T> &v1, const vector<T> &v2)
{
    if (v1.size() != v2.size())
        return false;
    auto it1 = v1.begin();
    auto it2 = v2.rbegin();
    while (it1 != v1.end())
    {
        if (*it1 != *it2)
            return false;
        ++it1;
        ++it2;
    }
    return true;
}

int main()
{
    vector<int> a{1, 2, 3}, b{3, 2, 1};
    cout << is_reverse(a, b) << '\n';
    a = {1, 2, 3, 4};
    b = {3, 2, 1};
    cout << is_reverse(a, b) << '\n';
    a = {1, 2, 3, 4};
    b = {1, 2, 3, 4};
    cout << is_reverse(a, b) << '\n';
    return 0;
}