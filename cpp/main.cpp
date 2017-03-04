#include <iostream>
#include <unordered_set>
#include <string>
#include <stdio.h>

#include "Utilities.h"
#include "Timer/Show.h"
#include "Daytime/Show.h"
#include "RequestReply/Show.h"
#include "PublishSubscribe/Show.h"
#include "ParallelPipeline/Show.h"

using namespace std;
using namespace Sunrise::NetworkPatterns;

void ShowHelp(const string &program)
{
    cout << "Using:" << endl;
    cout << program << " { Pattern Name | Timer | Daytime parameters | ... }" << endl;
}

template <typename TShow>
void Run(const string &name, int argc, char *argv[])
{
    TShow show;
    string showName(show.Name());
    if (name == to_lower(remove_space(showName)))
    {
        show.Run(argc, argv);
    }
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        string name(argv[1]);
        to_lower(trim(name));

        Run<Timer::Show>(name, argc, argv);
        Run<Daytime::Show>(name, argc, argv);
        Run<RequestReply::Show>(name, argc, argv);
        Run<PublishSubscribe::Show>(name, argc, argv);
        Run<ParallelPipeline::Show>(name, argc, argv);
    }
    else
    {
        string program(argv[0]);
        auto pos = program.find_last_of("/\\");
        if (pos != string::npos)
        {
            program.erase(0, ++pos);
        }
        ShowHelp(program);
    }

    getchar();

    return 0;
}