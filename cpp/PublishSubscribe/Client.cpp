#include "Client.h"
#include <iostream>
#include <sstream>
#include <zmq.hpp>
#include "../Utilities.h"

#pragma comment(lib, "libzmq.lib")

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace PublishSubscribe {

Client::Client()
{
    cout << "Client::Client()" << endl;
}

// 参考：http://zguide.zeromq.org/cpp:wuclient
void Client::Run(int argc, char *argv[]) const
{
    cout << "Client::Run(argc = " << argc << ", argv = " << GetArgv(argc, argv) << ")" << endl;

    zmq::context_t context(1);

    // Socket to talk to server
    cout << "Collecting updates from weather server..."
         << endl;
    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://localhost:5556");

    // Subscribe to zipcode, default is NYC, 10001
    const char *filter = (argc > 1) ? argv[1] : "10001 ";
    subscriber.setsockopt(ZMQ_SUBSCRIBE, filter, strlen(filter));

    // Process 100 updates
    int count = 100;
    long total_temp = 0;
    for (int i = 0; i < count; ++i)
    {
        zmq::message_t update;
        int zipcode, temperature, relhumidity;

        subscriber.recv(&update);

        istringstream iss(update.data<char>());
        iss >> zipcode >> temperature >> relhumidity;

        total_temp += temperature;
    }
    cout << "Average temperature for zipcode '" << filter
         << "' was " << (int)(total_temp / count) << "F"
         << endl;
}

} } }