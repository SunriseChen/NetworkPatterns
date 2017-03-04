#include "Utilities.h"

using namespace std;

namespace Sunrise { namespace NetworkPatterns {

const string GetArgv(int argc, char *argv[])
{
    string result = "[";
    for (int i = 0; i < argc; ++i)
    {
        result += "\"";
        result += argv[i];
        result += "\", ";
    }
    result.replace(result.size() - 2, 2, "]");

    return result;
}

} }