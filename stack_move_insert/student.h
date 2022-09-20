#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k, CP::stack<T> &s2, int m)
{
    // your code here
    if (m > s2.mSize)
        m = s2.mSize;
    if (k > mSize)
        k = mSize;
    if (mSize + m > mCap)
    {
        while (mCap < mSize + m)
            mCap *= 2;
        T *newData = new T[mCap];
        for (size_t i = 0; i < mSize; ++i)
        {
            newData[i] = mData[i];
        }
        delete[] mData;
        mData = newData;
    }
    for (size_t i = 1; i <= k; ++i)
    {
        mData[mSize - i + m] = mData[mSize - i];
    }
    for (size_t i = 0; i < m; ++i)
    {
        mData[mSize - k + i] = s2.mData[s2.mSize - m + i];
    }
    s2.mSize -= m;
    mSize += m;
}
#endif
