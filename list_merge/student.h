#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls)
{
    node *bk = mHeader->prev;
    for (CP::list<T> &l : ls)
    {
        bk->next = l.mHeader->next;
        l.mHeader->next->prev = bk;

        l.mHeader->next = l.mHeader;
        l.mHeader->prev = l.mHeader;

        l.mSize = 0;

        mSize += l.mSize;
        bk = l.mHeader->prev;
    }
    bk->next = mHeader;
    mHeader->prev = bk;
}

#endif
