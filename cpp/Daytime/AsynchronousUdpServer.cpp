#include "AsynchronousUdpServer.h"
#include <iostream>
#include <boost/asio.hpp>
#include "udp_server.h"

using namespace std;
using namespace boost::asio;

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

AsynchronousUdpServer::AsynchronousUdpServer()
{
    cout << "AsynchronousUdpServer::AsynchronousUdpServer()" << endl;
}

void AsynchronousUdpServer::Run() const
{
    cout << "AsynchronousUdpServer::Run()" << endl;

    try
    {
        io_service io_service;
        udp_server server(io_service);
        io_service.run();
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
}

} } }