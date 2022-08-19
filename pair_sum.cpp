#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    using namespace std;
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> cnt(1000000, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    sort(arr.begin(), arr.end());
    while (m--)
    {
        int check;
        bool found = false;
        cin >> check;
        for (int i : arr)
        {
            int rem = check - i;
            if (rem > 999999)
                continue;
            if (rem < 0)
                break;
            int c = cnt[rem];
            if (c >= 2 || (c == 1 && i != rem))
            {
                found = true;
                break;
            }
        }
        cout << (found ? "YES" : "NO") << '\n';
    }
    return 0;
}