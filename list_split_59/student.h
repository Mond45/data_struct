#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it, size_t pos)
{
    // write your code here
    CP::list<T> result;
    if (it == end())
        return result;
    node *before_split = it.ptr->prev;
    node *first = mHeader->next, *last = mHeader->prev;
    before_split->next = mHeader;
    mHeader->prev = before_split;
    it.ptr->prev = result.mHeader;
    result.mHeader->next = it.ptr;
    last->next = result.mHeader;
    result.mHeader->prev = last;
    result.mSize = mSize - pos;
    mSize = pos;
    return result;
}

#endif
