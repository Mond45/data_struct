#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
    {
        int mFront, mSize, mCap, last, operation;
        cin >> mFront >> mSize >> mCap >> last >> operation;
        if (last < mCap && mFront < mCap && mSize <= mCap && (mFront + mSize) % mCap == last)
        {
            cout << "OK\n";
        }
        else
        {
            switch (operation)
            {
            case 0:
            {
                cout << "WRONG\n";
                break;
            }
            case 1:
            {
                cout << "WRONG " << (last + mCap - mSize) % mCap << '\n';
                break;
            }
            case 2:
            {
                cout << "WRONG " << (last - mFront + mCap) % mCap << '\n';
                break;
            }
            case 3:
            {
                cout << "WRONG " << (mFront + mSize == last ? last + 1 : mFront - last + mSize) << '\n';
                break;
            }
            case 4:
            {
                cout << "WRONG " << (mFront + mSize) % mCap << '\n';
                break;
            }
            }
        }
    }
    return 0;
}