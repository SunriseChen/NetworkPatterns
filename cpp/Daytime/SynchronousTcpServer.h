#pragma once

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

class SynchronousTcpServer
{
public:
    SynchronousTcpServer();

    void Run() const;
};

} } }