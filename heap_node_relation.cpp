#include <iostream>

using namespace std;

inline bool is_ancestor(int anc, int des)
{
    while (des >= anc)
    {
        if (des == anc)
            return true;
        des = (des - 1) / 2;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << "a and b are the same node\n";
        }
        else if (a < b)
        {
            cout << (is_ancestor(a, b) ? "a is an ancestor of b\n" : "a and b are not related\n");
        }
        else if (b < a)
        {
            cout << (is_ancestor(b, a) ? "b is an ancestor of a\n" : "a and b are not related\n");
        }
    }
    return 0;
}