#pragma once

#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

namespace std
{

// trim from start
template <typename T>
inline basic_string<T> &trim_left(basic_string<T> &str)
{
    str.erase(str.begin(), find_if(str.begin(), str.end(),
                                   not1(ptr_fun<int, int>(isspace))));
    return str;
}

// trim from end
template <typename T>
inline basic_string<T> &trim_right(basic_string<T> &str)
{
    str.erase(find_if(str.rbegin(), str.rend(),
                      not1(ptr_fun<int, int>(isspace)))
                  .base(),
              str.end());
    return str;
}

// trim from both ends
template <typename T>
inline basic_string<T> &trim(basic_string<T> &str)
{
    return trim_left(trim_right(str));
}

template <typename T>
inline basic_string<T> &to_lower(basic_string<T> &str)
{
    transform(str.begin(), str.end(), str.begin(), ptr_fun<int, int>(tolower));
    return str;
}

template <typename T>
inline basic_string<T> &to_upper(basic_string<T> &str)
{
    transform(str.begin(), str.end(), str.begin(), ptr_fun<int, int>(toupper));
    return str;
}

template <typename T>
inline basic_string<T> &remove_space(basic_string<T> &str)
{
    str.erase(remove_if(str.begin(), str.end(), ptr_fun<int, int>(isspace)), str.end());
    return str;
}

template <typename ...Args>
inline void unused(Args&&...)
{
}

}