#pragma once

#include <string>
#include <sstream>

namespace Sunrise { namespace NetworkPatterns {

class ShowBase
{
    static std::string program;
    const std::string name;

public:
    const std::string & Name() const;
    void Run(int argc, char *argv[]);

protected:
    ShowBase(std::string &&name);
    virtual void DoRun(int argc, char *argv[]) = 0;

    template <typename T, typename... Args>
    void Start(std::string &&title, T &param, Args&... args);

private:
    template <typename T>
    static void Params(std::ostringstream &params, T &param);

    template <typename T, typename... Args>
    static void Params(std::ostringstream &params, T &param, Args&... args);
};

} }

#include "ShowBase.hpp"
