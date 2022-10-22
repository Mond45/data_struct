#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::shift_left()
{
    if (mSize <= 1)
        return;

    node *first = mHeader->next;
    mHeader->next = first->next;
    first->next->prev = mHeader;
    T tmp = std::move(first->data);
    delete first;

    node *last = mHeader->prev;
    node *n = new node(tmp, last, mHeader);
    last->next = n;
    mHeader->prev = n;
}

#endif
