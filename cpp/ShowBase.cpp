#include "ShowBase.h"
#include <iostream>

using namespace std;

namespace Sunrise { namespace NetworkPatterns {

string ShowBase::program;

ShowBase::ShowBase(string &&name)
    : name(name)
{
}

const string & ShowBase::Name() const
{
    return name;
}

void ShowBase::Run(int argc, char *argv[])
{
    cout << name << " Start:" << endl << endl;

    program = argv[0];
    DoRun(--argc, ++argv);

    cout << name << " Finished!" << endl << endl;
    cout << string(68, '=') << endl << endl;
}

} }