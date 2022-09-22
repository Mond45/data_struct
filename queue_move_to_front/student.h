#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos)
{
#define mod(a, b) (a >= b ? a - b : a)
    T tmp = std::move(mData[mod(mFront + pos, mCap)]);
    for (int i = pos - 1; i >= 0; --i)
    {
        mData[mod(mFront + i + 1, mCap)] = mData[mod(mFront + i, mCap)];
    }
    mData[mFront] = tmp;
}

#endif
