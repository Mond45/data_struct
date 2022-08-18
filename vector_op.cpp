#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    using namespace std;
    int q;
    vector<int> v;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "pb")
        {
            int val;
            cin >> val;
            v.push_back(val);
        }
        else if (cmd == "sa")
        {
            sort(v.begin(), v.end(), less<int>());
        }
        else if (cmd == "sd")
        {
            sort(v.begin(), v.end(), greater<int>());
        }
        else if (cmd == "r")
        {
            reverse(v.begin(), v.end());
        }
        else if (cmd == "d")
        {
            int pos;
            cin >> pos;
            v.erase(v.begin() + pos);
        }
    }
    for (auto x : v)
    {
        cout << x << ' ';
    }
    return 0;
}