#include "Timer.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::posix_time;

namespace Sunrise { namespace NetworkPatterns { namespace Timer {

namespace {

void print(const system::error_code & /*e*/)
{
    cout << "Hello, world!" << endl;
}

}

void Timer::Timer2() const
{
    cout << "Timer::Timer2()" << endl;

    io_service io;
    deadline_timer t(io, seconds(5));
    t.async_wait(&print);
    io.run();
}

} } }