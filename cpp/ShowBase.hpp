#pragma once

#include <cstdlib>

namespace Sunrise { namespace NetworkPatterns {

template <typename T, typename... Args>
void ShowBase::Start(std::string &&title, T &param, Args&... args)
{
    std::ostringstream params;
    Params(params, param, args...);
    std::string command = "start \"" + title + "\" " + program + " " + params.str();
    std::system(command.c_str());
}

template <typename T>
void ShowBase::Params(std::ostringstream &params, T &param)
{
    params << param;
}

template <typename T, typename... Args>
void ShowBase::Params(std::ostringstream &params, T &param, Args&... args)
{
    params << param << " ";
    Params(params, args...);
}

} }