#include <map>
#include <iostream>

int main()
{
    using namespace std;
    map<string, int> cnt;
    int n;
    cin >> n;
    int max = -1;
    while (n--)
    {
        string name;
        cin >> name;
        if ((++cnt[name]) > max)
        {
            max = cnt[name];
        }
    }
    for (auto it = cnt.rbegin(); it != cnt.rend(); ++it)
    {
        if (it->second == max)
        {
            cout << it->first << ' ' << it->second;
            break;
        }
    }
    return 0;
}