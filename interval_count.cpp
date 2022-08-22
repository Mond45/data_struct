#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        nums[i] = x;
    }
    sort(nums.begin(), nums.end());
    while (m--)
    {
        int p;
        cin >> p;
        int cnt = upper_bound(nums.begin(), nums.end(), p + k) - lower_bound(nums.begin(), nums.end(), p - k);
        cout << cnt << ' ';
    }
}