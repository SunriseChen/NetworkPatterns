#include "TcpClient.h"
#include <iostream>
#include <array>
#include <boost/asio.hpp>

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

TcpClient::TcpClient()
{
    cout << "TcpClient::TcpClient()" << endl;
}

void TcpClient::Run(const char *host) const
{
    cout << "TcpClient::Run(host = " << host << ")" << endl;

    try
    {
        io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(host, "daytime");
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

        tcp::socket socket(io_service);
        connect(socket, endpoint_iterator);

        std::array<char, 128> buf;
        system::error_code error;
        for (;;)
        {
            size_t len = socket.read_some(buffer(buf), error);

            if (error == error::eof)
                break; // Connection closed cleanly by peer.
            else if (error)
                throw system::system_error(error); // Some other error.

            cout.write(buf.data(), len);
        }
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
}

} } }