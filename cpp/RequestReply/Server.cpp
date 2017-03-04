#include "Server.h"
#include <iostream>
#include <string>
#include <zmq.hpp>
#include "../Utilities.h"

#pragma comment(lib, "libzmq.lib")

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace RequestReply {

Server::Server()
{
    cout << "Server::Server()" << endl;
}

// 参考：http://zguide.zeromq.org/cpp:hwserver
void Server::Run() const
{
    cout << "Server::Run()" << endl;

    // Prepare our context and socket
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:5555");

    while (true)
    {
        zmq::message_t request;

        // Wait for next request from client
        socket.recv(&request);
        string str(request.data<char>(), request.size());
        cout << "Received " << str << endl;

        // Do some 'work'
        sleep(1000);

        // Send reply back to client
        zmq::message_t reply(5);
        memcpy(reply.data(), "World", 5);
        socket.send(reply);
    }
}

} } }