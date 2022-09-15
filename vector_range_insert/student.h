#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last)
{
	// write your code here
	ptrdiff_t pos = position - mData;
	const size_t n = last - first;
	ensureCapacity(mSize + n);
	for (int i = mSize - 1; i >= pos; --i)
	{
		mData[i + n] = mData[i];
	}
	T *p = mData + pos;
	while (first != last)
	{
		*(p++) = *(first++);
	}
	mSize += n;
}

#endif
