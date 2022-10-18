#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include <cmath>

#define eq(a, b) (!mLess(a, b) && !mLess(b, a))
template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::find(T k) const
{
    // your code here
    for (size_t i = 0; i < mSize; ++i)
    {
        if (eq(k, mData[i]))
            return true;
    }
    return false;
}

template <typename T, typename Comp>
int CP::priority_queue<T, Comp>::find_level(T k) const
{
    using namespace std;
    int i = mSize - 1;
    for (; i >= 0; --i)
    {
        if (eq(mData[i], k))
            return (int)ceil(log2(i + 2)) - 1;
    }
    return -1;
}

#undef eq
#endif
