#ifndef SYSTEMMETRICS_H_INCLUDED
#define SYSTEMMETRICS_H_INCLUDED

#include <iostream>

#include "Corpus.h"
using namespace std;

class SystemMetrics
{
    public:
    /**execute, calls the corresponding daughter class**/
    virtual void execute() = 0;
    /**prints the query's result to screen
    *to be overriden by daughter classes
    **/
    virtual void print() = 0;

    protected:
    Corpus *corpus; //derived classes need to know where to look at, summary.csv
    string system; //derived classes need to know what system to work on
};

#endif // SYSTEMMETRICS_H_INCLUDED
