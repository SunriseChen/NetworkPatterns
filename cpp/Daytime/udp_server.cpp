#include "udp_server.h"
#include <boost/bind.hpp>
#include "common.h"

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

udp_server::udp_server(io_service &io_service)
    : socket_(io_service, udp::endpoint(udp::v4(), 13))
{
    start_receive();
}

void udp_server::start_receive()
{
    socket_.async_receive_from(buffer(recv_buffer_), remote_endpoint_,
                               bind(&udp_server::handle_receive, this,
                                    asio::placeholders::error,
                                    asio::placeholders::bytes_transferred));
}

void udp_server::handle_receive(const system::error_code &error, size_t /*bytes_transferred*/)
{
    if (!error || error == error::message_size)
    {
        std::shared_ptr<string> message(new string(make_daytime_string()));

        socket_.async_send_to(buffer(*message), remote_endpoint_,
                              bind(&udp_server::handle_send, this, message,
                                   asio::placeholders::error,
                                   asio::placeholders::bytes_transferred));

        start_receive();
    }
}

void udp_server::handle_send(std::shared_ptr<string> /*message*/,
                             const system::error_code & /*error*/,
                             size_t /*bytes_transferred*/)
{
}

} } }