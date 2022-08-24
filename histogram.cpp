#include <iostream>
#include <map>
#include <fstream>
#include <cctype>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // ifstream i("in.txt");
    // cin.rdbuf(i.rdbuf());
    // ofstream o("out.txt");
    // cout.rdbuf(o.rdbuf());
    int n;
    map<string, int> cnt;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        cnt[s]++;
    }
    for (auto &v : cnt)
    {
        if (v.second > 1)
            cout << v.first << ' ' << v.second << '\n';
    }
    return 0;
}