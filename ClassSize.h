#ifndef CLASSSIZE_H_INCLUDED
#define CLASSSIZE_H_INCLUDED

/**
*Written by : Chong Tze Wei
**/

#include "VersionMetrics.h"
#include "Version.h"

class ClassSize : public VersionMetrics
{
public:
    ClassSize(Version *pVersion);
    virtual void execute();
    virtual void print();

private:
    ifstream *classInfo; //pointer to the file stream in Version
    vector<string> sizes;
};

#endif // CLASSSIZE_H_INCLUDED
