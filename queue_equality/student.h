#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const
{
#define mod(a, b) (a >= b ? a - b : a)
    if (mSize != other.mSize)
        return false;
    for (size_t i = 0; i < mSize; ++i)
    {
        if (mData[mod(mFront + i, mCap)] != other.mData[mod(other.mFront + i, other.mCap)])
            return false;
    }
    return true;
}

#endif
