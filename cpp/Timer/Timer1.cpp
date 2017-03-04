#include "Timer.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::posix_time;

namespace Sunrise { namespace NetworkPatterns { namespace Timer {

Timer::Timer()
{
    cout << "Timer::Timer()" << endl;
}

void Timer::Timer1() const
{
    cout << "Timer::Timer1()" << endl;

    io_service io;
    deadline_timer t(io, seconds(5));
    t.wait();
    cout << "Hello, world!" << endl;
}

} } }