#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__

#include <vector>

namespace CP
{
    template <typename T>
    class stack
    {
    private:
        void mitosis(int, int);
        T *mData;
        size_t mSize, mCap;

    public:
        void pop();
        void push(T &&);
        T top();
    };
}

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    // if (mCap >= mSize + b - a + 1)
    // {
    //     T *tmp = new T[mCap], *p = tmp;
    //     for (int i = mSize - b - 1; i <= mSize - a - 1; ++i)
    //     {
    //         *(p++) = mData[i];
    //         *(p++) = mData[i];
    //     }
    //     for (int i = mSize - a; i < mSize; ++i)
    //     {
    //         *(p++) = mData[i];
    //     }
    //     for (int i = mSize - b - 1; i < mSize + b - a + 1; ++i)
    //     {
    //         mData[i] = *(tmp++);
    //     }
    //     delete[] tmp;
    //     mSize += b - a + 1;
    // }
    // else
    // {
    //     while (mCap < mSize + b - a + 1)
    //     {
    //         mCap *= 2;
    //     }
    //     T *newData = new T[mCap], *p = newData;
    //     for (int i = 0; i < mSize; ++i)
    //     {
    //         if (mSize - b - 1 <= i && i <= mSize - a - 1)
    //         {
    //             *(p++) = mData[i];
    //         }
    //         *(p++) = mData[i];
    //     }
    //     mSize += b - a + 1;
    //     delete[] mData;
    //     mData = newData;
    // }
    std::vector<T> tmp;
    for (int i = 0; i < a; ++i)
    {
        tmp.push_back(top());
        pop();
    }
    for (int i = 0; i < b - a + 1; ++i)
    {
        tmp.push_back(top());
        tmp.push_back(top());
        pop();
    }
    for (auto it = tmp.rbegin(); it != tmp.rend(); ++it)
    {
        push(*it);
    }
}
#endif