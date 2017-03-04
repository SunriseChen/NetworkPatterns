#pragma once

namespace Sunrise { namespace NetworkPatterns { namespace PublishSubscribe {

class Client
{
public:
    Client();

    void Run(int argc, char *argv[]) const;
};

} } }