#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_back(size_t pos)
{
#define mod(a, b) (a >= b ? a - b : a)
    // write your code here
    T tmp = std::move(mData[mod(mFront + pos, mCap)]);
    for (int i = pos + 1; i < mSize; ++i)
    {
        mData[mod(mFront + i - 1, mCap)] = mData[mod(mFront + i, mCap)];
    }
    mData[mod(mFront + mSize - 1, mCap)] = tmp;
}

#endif
