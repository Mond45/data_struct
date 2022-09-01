#include <set>
#include <vector>
#include <iostream>

using namespace std;

inline bool pwd_exist(const set<string> &pwd, const vector<int> &shift, string s)
{
    for (int i = 0; i < shift.size(); ++i)
    {
        s[i] = char('a' + ((s[i] - 'a' + shift[i]) % 26));
    }
    return pwd.find(s) != pwd.end();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, l;
    cin >> n >> m >> l;
    set<string> pwd;
    vector<int> shift(l);
    for (int i = 0; i < l; ++i)
    {
        cin >> shift[i];
    }
    while (n--)
    {
        string s;
        cin >> s;
        pwd.insert(s);
    }
    while (m--)
    {
        string s;
        cin >> s;
        cout << (pwd_exist(pwd, shift, s) ? "Match\n" : "Unknown\n");
    }
    return 0;
}