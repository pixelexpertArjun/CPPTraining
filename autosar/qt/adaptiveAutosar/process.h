#ifndef PROCESS_H
#define PROCESS_H

#include <QSharedDataPointer>

class processData;

class process
{
public:
    process();
    process(const process &);
    process &operator=(const process &);
    ~process();

private:
    QSharedDataPointer<processData> data;
};

#endif // PROCESS_H