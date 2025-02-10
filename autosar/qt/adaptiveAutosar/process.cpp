#include "process.h"

class processData : public QSharedData
{
public:

};

process::process() : data(new processData)
{

}

process::process(const process &rhs) : data(rhs.data)
{

}

process &process::operator=(const process &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

process::~process()
{

}
