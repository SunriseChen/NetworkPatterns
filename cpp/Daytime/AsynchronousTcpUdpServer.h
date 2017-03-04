#pragma once

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

class AsynchronousTcpUdpServer
{
public:
    AsynchronousTcpUdpServer();

    void Run() const;
};

} } }