#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data)
{
	// write your code here
	sort(data.begin(), data.end());
	const int newCap = (mSize + data.size()) <= mCap ? mCap : 2 * mCap;
	T *newData = new T[newCap], *p = newData;
	size_t id = 0;
	for (size_t i = 0; i < mSize; ++i)
	{
		if (i == data[id].first)
		{
			*(p++) = data[id++].second;
		}
		*(p++) = mData[i];
	}
	auto it = data.end() - 1;
	if (it->first == mSize)
	{
		*(p++) = it->second;
	}
	delete[] mData;
	mCap = newCap;
	mSize += data.size();
	mData = newData;
}

#endif
