#include "Client.h"
#include <iostream>
#include <string>
#include <zmq.hpp>

#pragma comment(lib, "libzmq.lib")

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace RequestReply {

Client::Client()
{
    cout << "Client::Client()" << endl;
}

// 参考：http://zguide.zeromq.org/cpp:hwclient
void Client::Run() const
{
    cout << "Client::Run()" << endl;

    // Prepare our context and socket
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);

    cout << "Connecting to hello world server..." << endl;
    socket.connect("tcp://localhost:5555");

    // Do 10 requests, waiting each time for a response
    for (int i = 0; i < 10; ++i)
    {
        zmq::message_t request(5);
        memcpy(request.data(), "Hello", 5);
        cout << "Sending Hello " << i << "..." << endl;
        socket.send(request);

        // Get the reply.
        zmq::message_t reply;
        socket.recv(&reply);
        string str(reply.data<char>(), reply.size());
        cout << "Received " << str << " " << i << endl;
    }
}

} } }