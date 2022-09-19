#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k)
{
	// write your code here
	if (!k)
		return;
	T *tmp = new T[last - first];
	for (auto it = first; it != last; ++it)
	{
		ptrdiff_t d = it - first - k;
		if (d < 0)
			d += last - first;
		tmp[d] = *it;
	}
	T *p = tmp;
	while (first != last)
	{
		*(first++) = *(p++);
	}
	delete[] tmp;
}

#endif
