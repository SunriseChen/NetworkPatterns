#include "tcp_server.h"
#include <boost/bind.hpp>

using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

tcp_server::tcp_server(io_service &io_service) : 
    acceptor_(io_service, tcp::endpoint(tcp::v4(), 13))
{
    start_accept();
}

void tcp_server::start_accept()
{
    tcp_connection::pointer new_connection =
        tcp_connection::create(acceptor_.get_io_service());

    acceptor_.async_accept(new_connection->socket(),
                           bind(&tcp_server::handle_accept, this, new_connection,
                                asio::placeholders::error));
}

void tcp_server::handle_accept(tcp_connection::pointer new_connection,
                    const system::error_code &error)
{
    if (!error)
    {
        new_connection->start();
    }

    start_accept();
}

} } }