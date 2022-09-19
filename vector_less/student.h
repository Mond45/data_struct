#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const
{
	// write your code here
	//  if you use std::vector, your score will be half (grader will report score BEFORE halving)
	if (!mSize && other.mSize)
		return true;
	const size_t min_size = other.mSize < mSize ? other.mSize : mSize;
	for (size_t i = 0; i < min_size; ++i)
	{
		if (mData[i] > other.mData[i])
			return false;
		else if (mData[i] < other.mData[i])
			return true;
	}
	if (mSize < other.mSize)
		return true;
	return false;
}

#endif
