#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m)
{
    // write your code here
#define valid_iter(x) (x >= mData && x < mData + mSize)
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
    using std::swap;
    if (!m)
        return false;
    if (!(valid_iter(a) && valid_iter(b) && valid_iter(a + m - 1) && valid_iter(b + m - 1)))
        return false;
    if (max(a, b) <= min(a + m - 1, b + m - 1))
        return false;
    while (m--)
    {
        swap(*(a++), *(b++));
    }
    return true;
}

#endif
