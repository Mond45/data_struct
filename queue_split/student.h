#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once
#include <vector>
#include <queue>
#include "queue.h"

template <typename T>
std::vector<CP::queue<T>> CP::queue<T>::split_queue(int k)
{
    std::vector<CP::queue<T>> qs(k);
    int n = mSize / k + (mSize % k != 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            if (mSize)
            {
                qs[j].push(front());
                pop();
            }
        }
    }
    return qs;
}

#endif
