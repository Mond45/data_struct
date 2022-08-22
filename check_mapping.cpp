#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    using namespace std;
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> seq[i];
    }
    sort(seq.begin(), seq.end());
    bool unique = true;
    if (seq[seq.size() - 1] > n)
        unique = false;
    else
    {
        int prev = seq[0] - 1;
        for (int i : seq)
        {
            if (prev == i)
            {
                unique = false;
                break;
            }
            prev = i;
        }
    }
    cout << (unique ? "YES\n" : "NO\n");
    return 0;
}