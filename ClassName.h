/**
*Written by : Chong Tze Wei
**/

#ifndef CLASSNAME_H_INCLUDED
#define CLASSNAME_H_INCLUDED

#include "VersionMetrics.h"
#include "Version.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
using namespace boost;
/**This class reads all the class names of a version of a system
*and displays it all to the console
**/

class ClassName : public VersionMetrics
{
public:
  ClassName(Version *pVersion); //gets a direct link to class-info.csv
  virtual void execute();
  virtual void print();
private:
  ifstream *classInfo; //pointer to the file stream in Version
  vector<string> names;
};

#endif // CLASSNAME_H_INCLUDED
