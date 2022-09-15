#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror()
{
	// write your code here
	ensureCapacity(2 * mSize);
	for (size_t i = mSize, k = 1; i < 2 * mSize; ++i, k += 2)
	{
		mData[i] = mData[i - k];
	}
	mSize = 2 * mSize;
}

#endif
