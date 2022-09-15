#include <iostream>

using namespace std;

int main()
{
    int n, i = 1;
    cin >> n;
    while (i < n)
    {
        i *= 2;
    }
    cout << i - n;
    return 0;
}