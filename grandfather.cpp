#include <iostream>
#include <fstream>
#include <map>

using ll = long long;

using namespace std;

ll find_grandfather(const map<ll, ll> &father, ll a)
{
    auto f = father.find(a);
    if (f == father.end())
        return -1;
    auto gf = father.find(f->second);
    if (gf == father.end())
        return -1;
    return gf->second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ifstream in("data.txt");
    // cin.rdbuf(in.rdbuf());
    // ofstream out("out.txt");
    // cout.rdbuf(out.rdbuf());

    int n, m;
    map<ll, ll> father;
    cin >> n >> m;
    while (n--)
    {
        ll f, s;
        cin >> f >> s;
        father[s] = f;
    }
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        ll ga, gb;
        if ((a != b) && ((ga = find_grandfather(father, a)) != -1) && ((gb = find_grandfather(father, b)) != -1) && (ga == gb))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}