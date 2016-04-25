#ifndef VERSIONCOUNT_H_INCLUDED
#define VERSIONCOUNT_H_INCLUDED

#include <iostream>

#include "SystemMetrics.h"
using namespace std;

/**
*counts the version of a spcified version
*gets the system to look at and finds the version count of the
*version from the metadata summary.csv
**/

class VersionCount : public SystemMetrics
{
    public:
    /**constructor, gets the system to look at and the Corpus**/
    VersionCount(string pSystem, Corpus *pCorpus);
    /**executes the class specific action**/
    virtual void execute();
    /**prints version count to screen, overrides parent method**/
    virtual void print();

    private:
    string versionCount;
};

#endif // VERSIONCOUNT_H_INCLUDED
