#include "stack.h"
#include "queue.h"

namespace CP
{
#define mod(a, b) ((a) > (b) ? (a) - (b) : (a))
    template <typename T>
    void stack<T>::appendStack(stack<T> s)
    {
        while (mCap < mSize + s.mSize)
        {
            mCap *= 2;
        }
        T *newData = new T[mCap], *p = newData;
        for (int i = 0; i < s.mSize; ++i)
        {
            *(p++) = s.mData[i];
        }
        for (size_t i = 0; i < mSize; ++i)
        {
            *(p++) = mData[i];
        }
        delete[] mData;
        mSize += s.mSize;
        mData = newData;
    }

    template <typename T>
    void stack<T>::appendQueue(queue<T> q)
    {
        while (mCap < mSize + q.mSize)
        {
            mCap *= 2;
        }
        T *newData = new T[mCap], *p = newData;
        for (int i = q.mSize - 1; i >= 0; --i)
        {
            *(p++) = q.mData[mod(q.mFront + i, q.mCap)];
        }
        for (size_t i = 0; i < mSize; ++i)
        {
            *(p++) = mData[i];
        }
        delete[] mData;
        mSize += q.mSize;
        mData = newData;
    }

    template <typename T>
    void queue<T>::appendStack(stack<T> s)
    {
        while (mCap < mSize + s.mSize)
        {
            mCap *= 2;
        }
        T *newData = new T[mCap], *p = newData;
        for (int i = 0; i < mSize; ++i)
        {
            *(p++) = mData[mod(mFront + i, mCap)];
        }
        for (int i = s.mSize - 1; i >= 0; --i)
        {
            *(p++) = s.mData[i];
        }
        // while (s.mSize)
        // {
        //     *(p++) = s.top();
        //     s.pop();
        // }
        delete[] mData;
        mFront = 0;
        mSize += s.mSize;
        mData = newData;
    }

    template <typename T>
    void queue<T>::appendQueue(queue<T> q)
    {
        while (mCap < mSize + q.mSize)
        {
            mCap *= 2;
        }
        T *newData = new T[mCap], *p = newData;
        for (int i = 0; i < mSize; ++i)
        {
            *(p++) = mData[mod(mFront + i, mCap)];
        }
        for (int i = 0; i < q.mSize; ++i)
        {
            *(p++) = q.mData[mod(q.mFront + i, q.mCap)];
        }
        // while (q.mSize)
        // {
        //     *(p++) = q.front();
        //     q.pop();
        // }
        delete[] mData;
        mFront = 0;
        mSize += q.mSize;
        mData = newData;
    }
}
