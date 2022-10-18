#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include <cmath>

template <typename T, typename Comp>
int CP::priority_queue<T, Comp>::height() const
{
    // write your code here
    if (!mSize)
        return -1;
    return (int)log2(mSize);
}

#endif
