#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

// DO NOT INCLUDE ANYTHING

template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first, typename std::set<T>::iterator last)
{
    // write your code ONLY here
    mCap = 1;
    auto d = std::distance(first, last);
    while (mCap < d)
        mCap *= 2;
    mData = new T[mCap];
    int i = 1;
    for (; first != last; ++first)
    {
        mData[d - (i++)] = *first;
    }
    mSize = d;
}

#endif
