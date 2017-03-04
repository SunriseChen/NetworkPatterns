#include "SynchronousTcpServer.h"
#include <iostream>
#include <boost/asio.hpp>
#include "common.h"

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

SynchronousTcpServer::SynchronousTcpServer()
{
    cout << "SynchronousTcpServer::SynchronousTcpServer()" << endl;
}

void SynchronousTcpServer::Run() const
{
    cout << "SynchronousTcpServer::Run()" << endl;

    try
    {
        io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));

        for (;;)
        {
            tcp::socket socket(io_service);
            acceptor.accept(socket);

            string message = make_daytime_string();

            system::error_code ignored_error;
            write(socket, buffer(message), ignored_error);
        }
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
}

} } }