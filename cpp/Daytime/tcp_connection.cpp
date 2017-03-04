#include "tcp_connection.h"
#include <boost/bind.hpp>
#include "common.h"

using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

tcp_connection::pointer tcp_connection::create(io_service &io_service)
{
    return pointer(new tcp_connection(io_service));
}

tcp::socket & tcp_connection::socket()
{
    return socket_;
}

void tcp_connection::start()
{
    message_ = make_daytime_string();

    async_write(socket_, buffer(message_),
                bind(&tcp_connection::handle_write, shared_from_this(),
                     asio::placeholders::error,
                     asio::placeholders::bytes_transferred));
}

tcp_connection::tcp_connection(io_service &io_service) : socket_(io_service)
{
}

void tcp_connection::handle_write(const system::error_code & /*error*/, size_t /*bytes_transferred*/)
{
}

} } }