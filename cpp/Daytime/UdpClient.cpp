#include "UdpClient.h"
#include <iostream>
#include <array>
#include <boost/asio.hpp>

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

UdpClient::UdpClient()
{
    cout << "UdpClient::UdpClient()" << endl;
}

void UdpClient::Run(const char *host) const
{
    cout << "UdpClient::Run(host = " << host <<  ")" << endl;

    try
    {
        io_service io_service;
        udp::resolver resolver(io_service);
        udp::resolver::query query(udp::v4(), host, "daytime");
        udp::endpoint receiver_endpoint = *resolver.resolve(query);

        udp::socket socket(io_service);
        socket.open(udp::v4());

        std::array<char, 1> send_buf = {{0}};
        socket.send_to(buffer(send_buf), receiver_endpoint);

        std::array<char, 128> recv_buf;
        udp::endpoint sender_endpoint;
        size_t len = socket.receive_from(buffer(recv_buf), sender_endpoint);

        cout.write(recv_buf.data(), len);
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
}

} } }