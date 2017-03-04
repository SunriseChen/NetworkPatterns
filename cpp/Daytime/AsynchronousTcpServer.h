#pragma once

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

class AsynchronousTcpServer
{
public:
    AsynchronousTcpServer();

    void Run() const;
};

} } }