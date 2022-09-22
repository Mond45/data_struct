#include <iostream>

using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    freopen("output/output.txt", "w", stdout);
    int n;
    cin >> n;
    while (n--)
    {
        int mFront, mSize, mCap, last, correction;
        cin >> mFront >> mSize >> mCap >> last >> correction;
        switch (correction)
        {
        case 0:
        {
            if (mFront >= mCap || mSize > mCap || last > mCap || mFront + mSize != last || (mFront == last && mSize != mCap))
                cout << "WRONG\n";
            else
                cout << "OK\n";
            break;
        }
        case 1:
        {
            if (mSize == mCap && mFront != last)
                cout << "WRONG " << last << '\n';
            else if (mFront + mSize != last)
                cout << "WRONG " << last - mSize << '\n';
            else
                cout << "OK\n";
            break;
        }
        case 2:
        {
            if (mFront == last && mSize != mCap)
                cout << "WRONG " << mCap << '\n';
            else if (mFront + mSize != last)
                cout << "WRONG " << last - mFront << '\n';
            else
                cout << "OK\n";
            break;
        }
        case 3:
        {
            if (mFront == last && mCap != mSize)
                cout << "WRONG " << mSize << '\n';

            else if (mCap < last || mCap < mFront || mCap < mSize)
                cout << "WRONG " << max(max(last, mFront) + 1, mSize) << '\n';

            else
                cout << "OK\n";
            break;
        }
        case 4:
        {
            if (mSize == mCap && last != mFront)
                cout << "WRONG " << mFront << '\n';
            else if (mFront + mSize != last)
                cout << "WRONG " << mFront + mSize << '\n';
            else
                cout << "OK\n";
            break;
        }
        }
    }
    return 0;
}