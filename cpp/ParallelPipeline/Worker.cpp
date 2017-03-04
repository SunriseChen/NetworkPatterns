#include "Worker.h"
#include <iostream>
#include <sstream>
#include <string>
#include <zmq.hpp>
#include "../Utilities.h"

#pragma comment(lib, "libzmq.lib")

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace ParallelPipeline {

Worker::Worker()
{
    cout << "Worker::Worker()" << endl;
}

// 参考：http://zguide.zeromq.org/cpp:taskwork
void Worker::Run() const
{
    cout << "Worker::Run()" << endl;

    zmq::context_t context(1);

    // Socket to receive messages on
    zmq::socket_t receiver(context, ZMQ_PULL);
    receiver.connect("tcp://localhost:5557");

    // Socket to send messages to
    zmq::socket_t sender(context, ZMQ_PUSH);
    sender.connect("tcp://localhost:5558");

    // Process tasks forever
    int workload; // Workload in msecs
    for (int i = 0;; ++i)
    {
        zmq::message_t message;
        receiver.recv(&message);
        string smessage(message.data<char>(), message.size());

        istringstream iss(smessage);
        iss >> workload;

        // Do the work
        sleep(workload);

        // Send results to sink
        message.rebuild();
        sender.send(message);

        // Simple progress indicator for the viewer
        if (i % 10 == 0)
            cout << ":" << flush;
        else
            cout << "." << flush;
    }
}

} } }