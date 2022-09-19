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
    while (K--)
    {
        T t = mData[mSize - 1];
        --mSize;
        s.emplace(std::move(t));
    }
    std::stack<T> s2;
    while (s.size())
    {
        T t = s.top();
        s.pop();
        s2.emplace(std::move(t));
    }
    return s2;
}

#endif
