#pragma once

#include "../ShowBase.h"

namespace Sunrise { namespace NetworkPatterns { namespace RequestReply {

class Show : public ShowBase
{
public:
    Show();

protected:
    virtual void DoRun(int argc, char *argv[]);
};

} } }