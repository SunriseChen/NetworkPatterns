#pragma once

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

class TcpClient
{
public:
    TcpClient();

    void Run(const char *host) const;
};

} } }