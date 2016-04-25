#ifndef RELEASEDATES_H_INCLUDED
#define RELEASEDATES_H_INCLUDED

#include <iostream>
#include <vector>
#include "SystemMetrics.h"
using namespace std;

/**
*This class displays the release dates of all versions of a system
*Note that it only displays the release dates, not the versions name itself
*above functionality can be added upon request
**/

class ReleaseDates : public SystemMetrics
{
public:
  ReleaseDates(string pSystem, Corpus *pCorpus);
  virtual void execute();
  virtual void print();
private:
  vector<string> dates;
};

#endif // RELEASEDATES_H_INCLUDED
