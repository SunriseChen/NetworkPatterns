#include "Sink.h"
#include <iostream>
#include <chrono>
#include <zmq.hpp>

#pragma comment(lib, "libzmq.lib")

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace ParallelPipeline {

Sink::Sink()
{
    cout << "Sink::Sink()" << endl;
}

// 参考：http://zguide.zeromq.org/cpp:tasksink
void Sink::Run() const
{
    cout << "Sink::Run()" << endl;

    // Prepare our context and socket
    zmq::context_t context(1);
    zmq::socket_t receiver(context, ZMQ_PULL);
    receiver.bind("tcp://*:5558");

    // Wait for start of batch
    zmq::message_t message;
    receiver.recv(&message);

    // Start our clock now
    auto start = chrono::high_resolution_clock::now();

    // Process 100 confirmations
    int tasks = 100;
    for (int i = 0; i < tasks; ++i)
    {
        receiver.recv(&message);
        if (i % 10 == 0)
            cout << ":" << flush;
        else
            cout << "." << flush;
    }

    // Calculate and report duration of batch
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = end - start;
    cout << "\nTotal elapsed time: " << elapsed.count() / 1000000.0 << " msec\n"
         << endl;
}

} } }