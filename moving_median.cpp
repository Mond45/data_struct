#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    vector<int> cur(v.begin(), v.begin() + w + 1);
    sort(cur.begin(), cur.end());
    cout << cur[w / 2] << ' ';
    for (int i = 1; i < n - w; ++i)
    {
        cur.erase(lower_bound(cur.begin(), cur.end(), v[i - 1]));
        cur.insert(lower_bound(cur.begin(), cur.end(), v[i + w]), v[i + w]);
        cout << cur[w / 2] << ' ';
    }
    return 0;
}