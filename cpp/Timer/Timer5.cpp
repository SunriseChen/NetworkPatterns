#include "Timer.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

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
        strand_(io),
        timer1_(io, seconds(1)),
        timer2_(io, seconds(1)),
        count_(0)
    {
        timer1_.async_wait(strand_.wrap(bind(&printer::print1, this)));
        timer2_.async_wait(strand_.wrap(bind(&printer::print2, this)));
    }

    ~printer()
    {
        cout << "Final count is " << count_ << endl;
    }

    void print1()
    {
        if (count_ < 10)
        {
            cout << "Timer 1: " << count_ << endl;
            ++count_;

            timer1_.expires_at(timer1_.expires_at() + seconds(1));
            timer1_.async_wait(strand_.wrap(bind(&printer::print1, this)));
        }
    }

    void print2()
    {
        if (count_ < 10)
        {
            cout << "Timer 2: " << count_ << endl;
            ++count_;

            timer2_.expires_at(timer2_.expires_at() + seconds(1));
            timer2_.async_wait(strand_.wrap(bind(&printer::print2, this)));
        }
    }

private:
    io_service::strand strand_;
    deadline_timer timer1_;
    deadline_timer timer2_;
    int count_;
};

}

void Timer::Timer5() const
{
    cout << "Timer::Timer5()" << endl;

    io_service io;
    printer p(io);
    thread t_io(bind(&io_service::run, &io));
    io.run();
    t_io.join();
}

} } }