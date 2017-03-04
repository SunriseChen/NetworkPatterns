#pragma once

#include <memory>
#include <string>
#include <boost/asio.hpp>

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

class udp_server
{
public:
    udp_server(boost::asio::io_service &io_service);

private:
    void start_receive();
    void handle_receive(const boost::system::error_code &error,
                        std::size_t bytes_transferred);
    void handle_send(std::shared_ptr<std::string> message,
                     const boost::system::error_code &error,
                     std::size_t bytes_transferred);

    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint remote_endpoint_;
    std::array<char, 1> recv_buffer_;
};

} } }