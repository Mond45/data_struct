#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <iostream>

template <typename T>
size_t CP::stack<T>::size() const
{
    // write your code here
    return v.size();
}

template <typename T>
const T &CP::stack<T>::top() const
{
    // write your code here
    return v.back();
}

template <typename T>
void CP::stack<T>::push(const T &element)
{
    // write your code here
    v.emplace_back(element);
}

template <typename T>
void CP::stack<T>::pop()
{
    // write your code here
    v.pop_back();
}

template <typename T>
void CP::stack<T>::deep_push(const T &element, int depth)
{
    // write your code here
    if (depth > v.size())
        depth = v.size();
    v.emplace(v.end() - depth, element);
}

template <typename T>
void CP::stack<T>::multi_push(const std::vector<T> &w)
{
    // write your code here
    for (auto &&e : w)
    {
        v.emplace_back(e);
    }
}

template <typename T>
void CP::stack<T>::pop_until(const T &e)
{
    // write your code here
    if (v.empty())
        return;
    T top = v.back();
    while (!v.empty() && top != e)
    {
        v.pop_back();
        top = v.back();
    }
}

#endif
