#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b)
{
    using std::swap;

    if (a == b || !mSize)
        return a;

    node *before = a.ptr->prev, *after = b.ptr, *last = b.ptr->prev, *first = a.ptr;

    for (iterator it = a; it != b;)
    {
        swap(it.ptr->prev, it.ptr->next);
        it = iterator(it.ptr->prev);
    }

    before->next = last;
    last->prev = before;
    first->next = after;
    after->prev = first;

    return iterator(last);

    // iterator before = iterator(a.ptr->prev);

    // std::vector<T> v;
    // for (iterator it = a; it != b;)
    // {
    //     v.push_back(*it);
    //     it.ptr->prev->next = it.ptr->next;
    //     it.ptr->next->prev = it.ptr->prev;
    //     delete it.ptr;
    //     it = it.ptr->next;
    // }
    // for (auto it = v.rbegin(); it != v.rend(); ++it)
    // {
    //     node *n = new node(*it, b.ptr->prev, b.ptr);
    //     b.ptr->prev->next = n;
    //     b.ptr->prev = n;
    // }

    // return ++before;
}

#endif
