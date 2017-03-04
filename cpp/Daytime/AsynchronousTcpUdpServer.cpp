#include "AsynchronousTcpUdpServer.h"
#include <iostream>
#include <boost/asio.hpp>
#include "tcp_server.h"
#include "udp_server.h"

using namespace std;
using namespace boost::asio;

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

AsynchronousTcpUdpServer::AsynchronousTcpUdpServer()
{
    cout << "AsynchronousTcpUdpServer::AsynchronousTcpUdpServer()" << endl;
}

void AsynchronousTcpUdpServer::Run() const
{
    cout << "AsynchronousTcpUdpServer::Run()" << endl;

    try
    {
        io_service io_service;
        tcp_server server1(io_service);
        udp_server server2(io_service);
        io_service.run();
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
}

} } }