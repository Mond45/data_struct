#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;
    int m, n;
    cin >> m >> n;
    vector<int> va(m), vb(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> va[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> vb[i];
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    auto ia = va.begin();
    auto ib = vb.begin();
    int prev = -1;
    while (ia != va.end() && ib != vb.end())
    {
        if (*ia > *ib)
        {
            ++ib;
        }
        else if (*ib > *ia)
        {
            ++ia;
        }
        else
        {
            if (prev != *ia)
            {
                cout << *ia << ' ';
                prev = *ia;
            }
            ++ia;
        }
    }
    return 0;
}