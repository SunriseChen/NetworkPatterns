#include "Show.h"
#include <iostream>
#include "../Utilities.h"
#include "Client.h"
#include "Server.h"

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace RequestReply {

Show::Show()
    : ShowBase("RequestReply")
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
            client.Run();
        }
        else if (funcName == "server")
        {
            Server server;
            server.Run();
        }
    }
    else
    {
        Start("服务器", "RequestReply", "Server");
        Start("客户端", "RequestReply", "Client");
   }

    cout << endl;
}

} } }