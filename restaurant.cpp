#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> time(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> time[i];
    }
    int cnt = 0, t = 0;
    while (true)
    {
        for (int i : time)
        {
            if (i == 0 || t % i == 0)
            {
                cout << t << '\n';
                if ((++cnt) >= m)
                {
                    return 0;
                }
            }
        }
        ++t;
    }
    return 0;
}