#include <iostream>
#include <set>

template <typename T>
auto less_than_eq(const std::set<T> &seq, const T &val)
{
    auto it = seq.lower_bound(val);
    if (*it == val)
        return it;
    else if (it != seq.begin()) // only case it==begin() is *it==val
        return --it;
    return seq.end();
}

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> dates;
    while (n--)
    {
        int year, month;
        cin >> year >> month;
        dates.emplace(year, month);
    }
    auto beg = dates.begin();
    while (m--)
    {
        int year, month;
        cin >> year >> month;
        auto p = make_pair(year, month);
        auto it = dates.lower_bound(p);
        if (*it == p)
        {
            cout << "0 0 ";
        }
        else if (it != beg)
        {
            --it;
            cout << it->first << ' ' << it->second << ' ';
        }
        else
        {
            cout << "-1 -1 ";
        }
    }
}