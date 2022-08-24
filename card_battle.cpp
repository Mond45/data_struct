#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> toe;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        toe.insert(x);
    }
    vector<vector<int>> opponents;
    opponents.reserve(m);
    for (int i = 0; i < m; ++i)
    {
        int k;
        cin >> k;
        opponents.push_back(vector<int>(k));
        for (int j = 0; j < k; ++j)
        {
            cin >> opponents[i][j];
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int v : opponents[i])
        {
            auto it = toe.upper_bound(v);
            if (it == toe.end())
            {
                // lose
                cout << i + 1;
                return 0;
            }
            else
            {
                toe.erase(it);
            }
        }
    }
    cout << m + 1;
    return 0;
}