template<class T>int CP::stack<T>::compare_reserve(const CP::stack<T>&a)const{int i = mCap-mSize-a.mCap+a.mSize;return i<0?-1:i!=0;}