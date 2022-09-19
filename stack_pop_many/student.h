#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::stack<T>::multi_pop(size_t K)
{
    // write your code here
    K = K > mSize ? mSize : K;
    while (K--)
    {
        --mSize;
    }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K)
{
    // write your code here
    //
    // don't forget to return an std::stack
    K = K > mSize ? mSize : K;
    std::stack<T> s;
    for (size_t i = mSize - K; i < mSize; ++i)
    {
        s.emplace(mData[i]);
    }
    mSize -= K;
    return s;
}

#endif
