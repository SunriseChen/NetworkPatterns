#include "Show.h"
#include <iostream>
#include "../Utilities.h"
#include "Ventilator.h"
#include "Worker.h"
#include "Sink.h"

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace ParallelPipeline {

Show::Show()
    : ShowBase("ParallelPipeline")
{
}

void Show::DoRun(int argc, char *argv[])
{
    if (argc > 1)
    {
        string funcName(argv[1]);
        to_lower(trim(funcName));
        if (funcName == "ventilator")
        {
            Ventilator ventilator;
            ventilator.Run();
        }
        else if (funcName == "worker")
        {
            Worker worker;
            worker.Run();
        }
        else if (funcName == "sink")
        {
            Sink sink;
            sink.Run();
        }
    }
    else
    {
        Start("推送器", "ParallelPipeline", "Ventilator");
        Start("工作者", "ParallelPipeline", "Worker");
        Start("工作者", "ParallelPipeline", "Worker");
        Start("工作者", "ParallelPipeline", "Worker");
        Start("接收器", "ParallelPipeline", "Sink");
   }

    cout << endl;
}

} } }