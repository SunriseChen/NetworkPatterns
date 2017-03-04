#include "Timer.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::posix_time;

namespace Sunrise { namespace NetworkPatterns { namespace Timer {

namespace {

void print(const system::error_code & /*e*/, deadline_timer *t, int *count)
{
    if (*count < 5)
    {
        cout << *count << endl;
        ++(*count);

        t->expires_at(t->expires_at() + seconds(1));
        t->async_wait(bind(print, asio::placeholders::error, t, count));
    }
}

}

void Timer::Timer3() const
{
    cout << "Timer::Timer3()" << endl;

    io_service io;
    int count = 0;
    deadline_timer t(io, seconds(1));
    t.async_wait(bind(print, asio::placeholders::error, &t, &count));
    io.run();
    cout << "Final count is " << count << endl;
}

} } }