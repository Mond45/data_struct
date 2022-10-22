#include <iostream>
#include <list>
#include <tuple>

using namespace std;

// template <typename T>
inline list<int>::iterator decrement(list<int>::iterator it, list<int> &l)
{
    if (it == l.begin())
        return l.end();
    return --it;
}

inline pair<int, int> check(list<int> &beads, list<int>::iterator pos)
{
    auto it = pos;
    int after = 0;
    ++it;
    for (; it != beads.end(); ++it)
    {
        if (*it == *pos)
            after++;
        else
            break;
    }
    int before = 0;
    it = decrement(pos, beads);
    for (; it != beads.end(); it = decrement(it, beads))
    {
        if (*it == *pos)
            ++before;
        else
            break;
    }
    return {before, after};
}

pair<bool, list<int>::iterator> destroy(list<int> &beads, list<int>::iterator pos, int before, int after)
{
    auto it = pos;
    for (int i = 0; i < after + 1; ++i)
    {
        it = beads.erase(it);
    }
    for (int i = 0; i < before; ++i)
    {
        --it;
        it = beads.erase(it);
    }
    auto it2 = decrement(it, beads);
    return {it2 != beads.end() && it != beads.end() && *it2 == *it, it};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, v; // #beads, insertion point, color
    cin >> n >> k >> v;
    list<int> beads;
    while (n--)
    {
        int x;
        cin >> x;
        beads.push_back(x);
    }

    auto it = beads.begin();
    for (int i = 0; i < k; ++i)
    {
        ++it;
    }
    it = beads.insert(it, v);
    int a, b;
    tie(a, b) = check(beads, it);
    // cout << a << ' ' << b;
    while (a + b >= 2)
    {
        bool cont;
        list<int>::iterator i;
        tie(cont, i) = destroy(beads, it, a, b);
        if (!cont)
            break;
        it = i;
        tie(a, b) = check(beads, it);
    }

    for (int i : beads)
    {
        cout << i << ' ';
    }
    return 0;
}