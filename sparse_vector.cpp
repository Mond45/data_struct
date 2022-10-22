#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dec(map<int, int>::iterator &it, map<int, int> &m)
{
    if (it == m.begin())
        it = m.end();
    else
        --it;
}

void insert_into_sv(map<int, int> &v, int pos, int value)
{
    auto it = v.end();
    dec(it, v);
    for (; it != v.end() && it->first >= pos; dec(it, v))
    {
        v[it->first + 1] = it->second;
        it = v.erase(it);
    }
    v[pos] = value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<int, int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        insert_into_sv(v, a, b);
    }
    cout << v.size() << "\n";
    for (auto &x : v)
    {
        cout << x.first << ": " << x.second << "\n";
    }
}