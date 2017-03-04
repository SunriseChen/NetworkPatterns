#pragma once

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

class AsynchronousUdpServer
{
public:
    AsynchronousUdpServer();

    void Run() const;
};

} } }