template <class T, class C>
void CP::priority_queue<T, C>::change_value(size_t p, const T &v)
{
    mData[p] = v;
    fixDown(p);
    fixUp(p);
}