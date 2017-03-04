#include "SynchronousUdpServer.h"
#include <iostream>
#include <array>
#include <boost/asio.hpp>
#include "common.h"

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

SynchronousUdpServer::SynchronousUdpServer()
{
    cout << "SynchronousUdpServer::SynchronousUdpServer()" << endl;
}

void SynchronousUdpServer::Run() const
{
    cout << "SynchronousUdpServer::Run()" << endl;

    try
    {
        io_service io_service;
        udp::socket socket(io_service, udp::endpoint(udp::v4(), 13));

        for (;;)
        {
            std::array<char, 1> recv_buf;
            udp::endpoint remote_endpoint;
            system::error_code error;
            socket.receive_from(buffer(recv_buf), remote_endpoint, 0, error);

            if (error && error != error::message_size)
                throw system::system_error(error);

            string message = make_daytime_string();

            system::error_code ignored_error;
            socket.send_to(buffer(message), remote_endpoint, 0, ignored_error);
        }
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
}

} } }