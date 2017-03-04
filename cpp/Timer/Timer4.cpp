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

class printer
{
public:
    printer(io_service &io) : 
        timer_(io, seconds(1)),
        count_(0)
    {
        timer_.async_wait(bind(&printer::print, this));
    }

    ~printer()
    {
        cout << "Final count is " << count_ << endl;
    }

    void print()
    {
        if (count_ < 5)
        {
            cout << count_ << endl;
            ++count_;

            timer_.expires_at(timer_.expires_at() + seconds(1));
            timer_.async_wait(bind(&printer::print, this));
        }
    }

private:
    deadline_timer timer_;
    int count_;
};

}

void Timer::Timer4() const
{
    cout << "Timer::Timer4()" << endl;

    io_service io;
    printer p(io);
    io.run();
}

} } }