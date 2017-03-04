#include "Server.h"
#include <iostream>
#include <random>
#include <stdio.h>
#include <zmq.hpp>
#include "../Utilities.h"

#pragma comment(lib, "libzmq.lib")

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace PublishSubscribe {

Server::Server()
{
    cout << "Server::Server()" << endl;
}

// 参考：http://zguide.zeromq.org/cpp:wuserver
void Server::Run() const
{
    cout << "Server::Run()" << endl;

    // Prepare our context and publisher
    zmq::context_t context(1);
    zmq::socket_t publisher(context, ZMQ_PUB);
    publisher.bind("tcp://*:5556");
    //publisher.bind("ipc://weather.ipc"); // Not usable on Windows.

    // Initialize random number generator
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<> dist;
    while (true)
    {
        // Get values that will fool the boss
        int zipcode = within(100000);
        int temperature = within(215) - 80;
        int relhumidity = within(50) + 10;

        // Send message to all subscribers
        zmq::message_t message(20);
        snprintf(message.data<char>(), 20,
                 "%05d %d %d", zipcode, temperature, relhumidity);
        publisher.send(message);
    }
}

} } }