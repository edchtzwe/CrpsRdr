#ifndef FIELDCOUNT_H_INCLUDED
#define FIELDCOUNT_H_INCLUDED

/**
*Written by : Chong Tze Wei
**/

#include "VersionMetrics.h"
#include "Version.h"

/**This class displays all the
*number of fields of a
*specific version of a system
**/

class FieldCount : public VersionMetrics
{
public:
    FieldCount(Version *pVersion);
    virtual void execute();
    virtual void print();

private:
    ifstream *classInfo; //pointer to the file stream in Version
    vector<string> fields;
};

#endif // FIELDCOUNT_H_INCLUDED
