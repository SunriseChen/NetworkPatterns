#include "common.h"
#include <ctime>

using namespace std;

namespace Sunrise { namespace NetworkPatterns { namespace Daytime {

string make_daytime_string()
{
    time_t now = time(0);
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4996)
#endif
    return ctime(&now);
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
}

} } }