#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T &value, iterator a, iterator b, CP::list<T> &output)
{
    int cnt = 0;
    iterator beg = output.begin();
    for (iterator it = a; it != b; ++it)
    {
        if (*it == value)
        {
            ++cnt;
            it.ptr->prev->next = it.ptr->next;
            it.ptr->next->prev = it.ptr->prev;
            delete it.ptr;
            mSize--;
        }
    }
    while (cnt--)
    {
        node *n = new node(value, beg.ptr->prev, beg.ptr);
        beg.ptr->prev->next = n;
        beg.ptr->prev = n;
        output.mSize++;
    }
}

#endif
