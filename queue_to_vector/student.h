#ifndef __STUDENT_H_
#define __STUDENT_H_

#define mod(a, b) (a >= b ? a - b : a)
template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const
{
    // write your code only here
    if (k > mSize)
        k = mSize;
    std::vector<T> res(k);
    for (size_t i = 0; i < k; ++i)
    {
        res[i] = mData[mod(mFront + i, mCap)];
    }
    return res;
}

template <typename T>
CP::queue<T>::queue(iterator from, iterator to)
{
    ptrdiff_t d = to - from;
    mSize = d;
    mCap = d;
    mFront = 0;
    mData = new T[d];
    T *p = mData;
    for (; from != to; ++from)
    {
        *(p++) = *from;
    }
}

#endif
