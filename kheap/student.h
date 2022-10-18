#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>

template <typename T, typename Comp>
void CP::priority_queue<T, Comp>::fixUp(size_t idx)
{
    size_t currentNode = idx;
    T val = mData[idx];
    while (currentNode != 0)
    {
        size_t parent = (currentNode - 1) / 4;
        if (mLess(mData[parent], val))
        {
            mData[currentNode] = mData[parent];
        }
        else
        {
            break;
        }
        currentNode = parent;
    }
    mData[currentNode] = val;
}

template <typename T, typename Comp>
void CP::priority_queue<T, Comp>::fixDown(size_t idx)
{
    using namespace std;
    T val = mData[idx];
    size_t currentNode = idx;
    while (currentNode * 4 + 1 < mSize)
    {
        bool valid = true;
        size_t maxChild = -1;
        for (int i = 1; i <= 4; ++i)
        {
            if (currentNode * 4 + i < mSize)
            {
                if (mLess(val, mData[currentNode * 4 + i]))
                    valid = false;
                if (maxChild == -1 || mLess(mData[maxChild], mData[currentNode * 4 + i]))
                    maxChild = currentNode * 4 + i;
            }
        }
        if (valid)
            break;
        mData[currentNode] = mData[maxChild];
        currentNode = maxChild;
    }
    mData[currentNode] = val;
}

#endif
