#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const
{
    // write your code here
    using namespace std;
    vector<vector<T>> res(k);
    const int rem = mSize % k, div = mSize / k;
    int idx = mSize - 1;
    for (int i = 0; i < k; ++i)
    {
        vector<T> tmp;
        int n = div + (i < rem);
        while (n--)
        {
            tmp.emplace_back(mData[idx--]);
        }
        res[i] = move(tmp);
    }
    return res;
}
#endif
