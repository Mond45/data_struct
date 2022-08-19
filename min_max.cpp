#include <iostream>
#include <vector>

int main()
{
    using namespace std;
    int n{}, m{}, c{}; // n rows, m cols
    cin >> n >> m >> c;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < c; ++i)
    {
        int r1{}, r2{}, c1{}, c2{};
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 > r2 || c1 > c2)
        {
            cout << "INVALID\n";
        }
        else if (r2 < 1 || r1 > n || c1 > m || c2 < 1)
        {
            cout << "OUTSIDE\n";
        }
        else
        {
            r1 = max(r1, 1);
            c1 = max(c1, 1);
            r2 = min(r2, n);
            c2 = min(c2, m);
            int res{matrix[r1 - 1][c1 - 1]};
            for (int i = r1 - 1; i < r2; ++i)
            {
                for (int j = c1 - 1; j < c2; ++j)
                {
                    res = max(matrix[i][j], res);
                }
            }
            cout << res << '\n';
        }
    }
    return 0;
}
