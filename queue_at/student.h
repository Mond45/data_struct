template <class T>
T CP::queue<T>::operator[](int i) { return mData[(mFront + i + mSize * (i < 0)) % mCap]; }
