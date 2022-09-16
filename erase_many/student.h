#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos)
{
    T *newData = new T[mCap];
    T *p = newData;
    size_t ip = 0;
    for (size_t i = 0; i < mSize; ++i)
    {
        if (ip < pos.size() && i == pos[ip])
        {
            ++ip;
        }
        else
        {
            *(p++) = mData[i];
        }
    }
    delete[] mData;
    mSize -= pos.size();
    mData = newData;

    // int i = 0;
    // T *p = mData;
    // while (i < pos[0])
    // {
    //     *(p++) = mData[i];
    //     ++i;
    // }
    // for (int i = 0; i < pos.size() - 1; ++i)
    // {
    //     for (int j = pos[i] + 1; j < pos[i + 1]; ++j)
    //         *(p++) = mData[j];
    // }
    // i = *(pos.end() - 1) + 1;
    // while (i < mSize)
    // {
    //     *(p++) = mData[i];
    //     ++i;
    // }
    // mSize -= pos.size();
}

#endif
