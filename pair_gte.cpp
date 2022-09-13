namespace CP
{
    template <typename T1, typename T2>
    class pair
    {
    public:
        T1 first;
        T2 second;
        bool operator>=(const pair &) const;
    };
}

template <typename T1, typename T2>
bool CP::pair<T1, T2>::operator>=(const CP::pair<T1, T2> &other) const
{
    return this->first > other.first || this->first == other.first && this->second >= other.second;
}