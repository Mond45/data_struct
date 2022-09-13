#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void member_multiply(vector<int> &v,
                     vector<pair<vector<int>::iterator, int>> &multiply)
{
    // write your code here
    sort(multiply.begin(), multiply.end());
    vector<int> v2;
    size_t idx = 0;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it == multiply[idx].first)
        {
            v2.insert(v2.end(), multiply[idx].second + 1, *it);
            idx++;
        }
        else
        {
            v2.push_back(*it);
        }
    }
    v = v2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator, int>> multiply(m);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        multiply[i].first = v.begin() + a;
        multiply[i].second = b;
    }
    member_multiply(v, multiply);
    cout << "======= result ========" << endl;
    cout << v.size() << endl;
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}