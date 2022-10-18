#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    int k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << n - 1;
    }
    else
    {
        cout << ceil(log(n * (k - 1) + 1) / log(k)) - 1;
    }
    return 0;
}