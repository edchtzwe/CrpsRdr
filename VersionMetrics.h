/**
*Written by : Chong Tze Wei
**/

#ifndef VERSIONMETRICS_H_INCLUDED
#define VERSIONMETRICS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>

#include "Version.h"
using namespace std;

/**abstract class**/

class VersionMetrics
{
public:
  virtual void execute() = 0;
  virtual void print() = 0;
protected:
  Version *version;
};

#endif // VERSIONMETRICS_H_INCLUDED
