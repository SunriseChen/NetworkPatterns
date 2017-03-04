#include "Ventilator.h"
#include <iostream>
#include <random>
#include <cstdio>
//#include <stdio.h>
#include <zmq.hpp>
#include "../Utilities.h"

#if defined(_MSC_VER)
#pragma comment(lib, "libzmq.lib")
#endif

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace ParallelPipeline {

Ventilator::Ventilator()
{
    cout << "Ventilator::Ventilator()" << endl;
}

// 参考：http://zguide.zeromq.org/cpp:taskvent
void Ventilator::Run() const
{
    cout << "Ventilator::Run()" << endl;

    zmq::context_t context(1);

    // Socket to send messages on
    zmq::socket_t sender(context, ZMQ_PUSH);
    sender.bind("tcp://*:5557");

    cout << "Press Enter when the workers are ready: " << endl;
    getchar();
    cout << "Sending tasks to workers..." << endl;

    // The first message is "0" and signals start of batch
    zmq::socket_t sink(context, ZMQ_PUSH);
    sink.connect("tcp://localhost:5558");
    zmq::message_t message(2);
    memcpy(message.data(), "0", 1);
    sink.send(message);

    // Initialize random number generator
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<> dist;

    // Send 100 tasks
    int tasks = 100;
    int total_msec = 0; // Total expected cost in msecs
    for (int i = 0; i < tasks; ++i)
    {
        // Random workload from 1 to 100msecs
        int workload = within(100) + 1;
        total_msec += workload;

        message.rebuild(10);
        memset(message.data(), '\0', 10);
        snprintf(message.data<char>(), 10, "%d", workload);
        sender.send(message);
    }
    cout << "Total expected cost: " << total_msec << " msec" << endl;
    sleep(1); // Give 0MQ time to deliver
}

} } }