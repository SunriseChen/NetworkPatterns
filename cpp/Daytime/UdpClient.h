#pragma once

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

class UdpClient
{
public:
    UdpClient();

    void Run(const char *host) const;
};

} } }