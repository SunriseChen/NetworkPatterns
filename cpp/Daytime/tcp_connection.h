#pragma once

#include <memory>
#include <string>
#include <boost/asio.hpp>

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

class tcp_connection : public std::enable_shared_from_this<tcp_connection>
{
public:
    typedef std::shared_ptr<tcp_connection> pointer;

    static pointer create(boost::asio::io_service &io_service);
    boost::asio::ip::tcp::socket & socket();
    void start();

private:
    tcp_connection(boost::asio::io_service &io_service);

    void handle_write(const boost::system::error_code &error, std::size_t bytes_transferred);

    boost::asio::ip::tcp::socket socket_;
    std::string message_;
};

} } }