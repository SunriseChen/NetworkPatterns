#pragma once

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

class SynchronousUdpServer
{
public:
    SynchronousUdpServer();

    void Run() const;
};

} } }