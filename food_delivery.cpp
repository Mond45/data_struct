#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> goals(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> goals[i];
    }
    vector<int> goals_sorted = goals;
    sort(goals_sorted.begin(), goals_sorted.end());
    queue<int> gf, dm;
    int cnt = 0;
    int got = 0, idx = 0;
    map<int, int> res;
    while (n--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int r, p;
            cin >> r >> p;
            if (r == 1)
            {
                gf.push(p);
            }
            else if (r == 2)
            {
                dm.push(p);
            }
        }
        else if (c == 2)
        {

            if (dm.empty())
            {
                got += gf.front();
                gf.pop();
            }
            else if (gf.empty())
            {
                got += dm.front();
                dm.pop();
            }
            else
            {
                int dt, gt;
                dt = dm.front();
                gt = gf.front();
                if (dt < gt)
                {
                    got += dt;
                    dm.pop();
                }
                else if (gt < dt)
                {
                    got += gt;
                    gf.pop();
                }
                else
                {
                    got += gt;
                    gf.pop();
                }
            }
            ++cnt;
            while (idx < m && got >= goals_sorted[idx])
            {
                res[goals_sorted[idx]] = cnt;
                ++idx;
            }
        }
    }
    for (int i : goals)
    {
        auto r = res[i];
        cout << (r == 0 ? -1 : r) << ' ';
    }
    return 0;
}
