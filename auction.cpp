#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a;
    cin >> n >> m >> a;
    vector<int> cnt(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> cnt[i];
    }
    vector<unordered_map<int, int>> bid(n);
    while (a--)
    {
        char cmd;
        cin >> cmd;
        if (cmd == 'B')
        {
            int u, i, v;
            cin >> u >> i >> v;
            bid[i - 1][u] = v;
        }
        else if (cmd == 'W')
        {
            int u, i;
            cin >> u >> i;
            bid[i - 1].erase(u);
        }
    }
    vector<vector<int>> res(m);
    for (int i = 0; i < n; ++i)
    {
        priority_queue<pair<int, int>> pq;
        for (const auto &p : bid[i])
        {
            pq.emplace(p.second, p.first);
        }
        int c = cnt[i];
        while (!pq.empty() && c--)
        {
            auto p = pq.top();
            // price,id
            res[p.second - 1].push_back(i + 1);
            pq.pop();
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (!res[i].empty())
        {
            for (int j : res[i])
            {
                cout << j << ' ';
            }
            cout << '\n';
        }
        else
        {
            cout << "NONE\n";
        }
    }
    return 0;
}