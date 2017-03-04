#include "Show.h"
#include <iostream>
#include "../Utilities.h"
#include "Timer.h"

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace Timer {

Show::Show()
    : ShowBase("Timer")
{
}

void Show::DoRun(int argc, char *argv[])
{
    unused(argc, argv);

    Timer timer;
    timer.Timer1();
    cout << endl;

    timer.Timer2();
    cout << endl;

    timer.Timer3();
    cout << endl;

    timer.Timer4();
    cout << endl;

    timer.Timer5();
    cout << endl;
}

} } }