#include "AsynchronousTcpServer.h"
#include <iostream>
#include <boost/asio.hpp>
#include "tcp_server.h"

using namespace std;
using namespace boost::asio;

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

AsynchronousTcpServer::AsynchronousTcpServer()
{
    cout << "AsynchronousTcpServer::AsynchronousTcpServer()" << endl;
}

void AsynchronousTcpServer::Run() const
{
    cout << "AsynchronousTcpServer::Run()" << endl;

    try
    {
        io_service io_service;
        tcp_server server(io_service);
        io_service.run();
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
}

} } }