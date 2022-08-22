#include <iostream>
#include <map>

int main()
{
    using namespace std;
    std::map<int, int> cnt;
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    while (m--)
    {
        int x;
        bool found = false;
        cin >> x;
        for (auto &v : cnt)
        {
            int rem = x - v.first;
            if (rem < 0)
                break;
            auto it = cnt.find(rem);
            if (it != cnt.end() && (it->second >= 2 || (it->second == 1 && it->first != v.first)))
            {
                found = true;
                break;
            }
        }
        cout << (found ? "YES\n" : "NO\n");
    }
}