#include "Show.h"
#include <iostream>
#include "../Utilities.h"
#include "TcpClient.h"
#include "SynchronousTcpServer.h"
#include "AsynchronousTcpServer.h"
#include "UdpClient.h"
#include "SynchronousUdpServer.h"
#include "AsynchronousUdpServer.h"
#include "AsynchronousTcpUdpServer.h"

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

Show::Show()
    : ShowBase("Daytime")
{
}

void Show::DoRun(int argc, char *argv[])
{
    if (argc > 1)
    {
        string funcName(argv[1]);
        to_lower(trim(funcName));
        if (funcName == "tcpclient")
        {
            TcpClient client;
            client.Run(argv[2]);
        }
        else if (funcName == "synchronoustcpserver")
        {
            SynchronousTcpServer server;
            server.Run();
        }
        else if (funcName == "asynchronoustcpserver")
        {
            AsynchronousTcpServer server;
            server.Run();
        }
        else if (funcName == "udpclient")
        {
            UdpClient client;
            client.Run(argv[2]);
        }
        else if (funcName == "synchronousudpserver")
        {
            SynchronousUdpServer server;
            server.Run();
        }
        else if (funcName == "asynchronousudpserver")
        {
            AsynchronousUdpServer server;
            server.Run();
        }
        else if (funcName == "asynchronoustcpudpserver")
        {
            AsynchronousTcpUdpServer server;
            server.Run();
        }
    }
    else
    {
        Start("服务器", "Daytime", "AsynchronousTcpUdpServer");
        Start("客户端", "Daytime", "TcpClient", "localhost");
        Start("客户端", "Daytime", "UdpClient", "localhost");
    }

    cout << endl;
}

} } }