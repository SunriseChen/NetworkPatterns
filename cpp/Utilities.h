#pragma once

#include <string>
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n) Sleep(n)
#endif

#define within(num) (dist(gen) % (num))

namespace std
{

template <typename T>
basic_string<T> &trim_left(basic_string<T> &str);

template <typename T>
basic_string<T> &trim_right(basic_string<T> &str);

template <typename T>
basic_string<T> &trim(basic_string<T> &str);

template <typename T>
basic_string<T> &tolower(basic_string<T> &str);

template <typename T>
basic_string<T> &toupper(basic_string<T> &str);

template <typename T>
basic_string<T> &remove_space(basic_string<T> &str);

template <typename... Args>
void unused(Args&&...);

}

namespace Sunrise { namespace NetworkPatterns {

const std::string GetArgv(int argc, char *argv[]);

} }

#include "Utilities.hpp"