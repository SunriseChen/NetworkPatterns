#include "Show.h"
#include <iostream>
#include "../Utilities.h"
#include "Client.h"
#include "Server.h"

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace PublishSubscribe {

Show::Show()
    : ShowBase("PublishSubscribe")
{
}

void Show::DoRun(int argc, char *argv[])
{
    if (argc > 1)
    {
        string funcName(argv[1]);
        to_lower(trim(funcName));
        if (funcName == "client")
        {
            Client client;
            client.Run(--argc, ++argv);
        }
        else if (funcName == "server")
        {
            Server server;
            server.Run();
        }
    }
    else
    {
        Start("服务器", "PublishSubscribe", "Server");
        Start("客户端", "PublishSubscribe", "Client");
        Start("客户端", "PublishSubscribe", "Client", "12345");
        Start("客户端", "PublishSubscribe", "Client", "99999");
    }

    cout << endl;
}

} } }