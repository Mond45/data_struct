#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a;
    cin >> n >> a;
    queue<int> q;
    q.push(a);
    vector<int> res;
    while (!q.empty())
    {
        int c = q.front();
        res.emplace_back(c);
        q.pop();
        if (2 * c + 1 < n)
            q.push(2 * c + 1);
        if (2 * c + 2 < n)
            q.push(2 * c + 2);
    }
    cout << res.size() << '\n';
    for (int i : res)
    {
        cout << i << ' ';
    }
    return 0;
}