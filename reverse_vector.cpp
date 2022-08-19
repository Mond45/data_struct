#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void swap_(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

void reverse(vector<int> &v, int a, int b)
{
    for (size_t i = 0; i < (b - a + 1) / 2; ++i)
    {
        swap_(v[a + i], v[b - i]);
    }
}

int main()
{
    // read input
    int n, a, b;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    // call function
    reverse(v, a, b);
    // display content of the vector
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}