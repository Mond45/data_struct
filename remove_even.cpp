#include <iostream>
#include <vector>

using namespace std;

vector<string> punch(vector<string> &v, vector<string>::iterator it, int k)
{
    int cnt = k, a = 0;
    while (it != v.begin() && cnt-- > 0)
    {
        --it;
        ++a;
    }
    cnt = a + k + 1;
    while (it != v.end() && cnt-- > 0)
    {
        it = v.erase(it);
    }
    return v;
}

int main()
{
    int n, j, k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result)
    {
        cout << x << endl;
    }
}