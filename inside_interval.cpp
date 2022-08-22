#include <iostream>
#include <set>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> intervals;
    while (n--)
    {
        int l, u;
        cin >> l >> u;
        intervals.insert({l, u});
    }
    while (m--)
    {
        int x;
        cin >> x;
        auto it = intervals.lower_bound({x, x});
        if (it->first == x || (it != intervals.begin() && (--it)->first <= x && it->second >= x))
            cout << "1 ";
        else
            cout << "0 ";
    }
    return 0;
}
