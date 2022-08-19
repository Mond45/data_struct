#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

int main()
{
    using namespace std;
    cout << fixed << setprecision(2);
    int n;
    cin >> n;
    // pair: count,sum
    map<string, pair<int, int>> sub_score;
    map<string, pair<int, int>> lec_score;
    while (n--)
    {
        string sub, lec;
        int score;
        cin >> sub >> lec >> score;
        auto &s = sub_score[sub];
        auto &l = lec_score[lec];
        s.first++;
        l.first++;
        s.second += score;
        l.second += score;
    }
    for (auto &v : sub_score)
    {
        cout << v.first << ' ' << (float(v.second.second) / (v.second.first)) << '\n';
    }
    for (auto &v : lec_score)
    {
        cout << v.first << ' ' << (float(v.second.second) / (v.second.first)) << '\n';
    }
    return 0;
}