#ifndef __STUDENT_H_
#define __STUDENT_H_

// you can include any other file here
// you are allow to use any data structure
#include <unordered_set>

template <typename T>
void CP::vector<T>::uniq()
{
	// do someting here
	std::unordered_set<T> s;
	T *p = mData;
	for (size_t i = 0; i < mSize; ++i)
	{
		if (s.find(mData[i]) == s.end())
		{
			*(p++) = mData[i];
			s.emplace(mData[i]);
		}
	}
	mSize = s.size();
}

#endif
