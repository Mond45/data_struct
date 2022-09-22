#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <unordered_map>

template <typename T>
std::vector<std::pair<T, size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const
{
    // write your code here
#define mod(a, b) (a >= b ? a - b : a)
    using namespace std;
    vector<pair<T, size_t>> res;
    unordered_map<T, size_t> cnt;
    for (size_t i = 0; i < mSize; ++i)
    {
        cnt[mData[mod(mFront + i, mCap)]]++;
    }
    for (const T &e : k)
    {
        res.emplace_back(e, cnt[e]);
    }
    return res;
}

#endif
