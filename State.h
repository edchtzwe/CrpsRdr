#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

#include <vector>
#include <fstream>

#include "SystemMetrics.h"

class State : public SystemMetrics
{
public:
  State(string pSystem, Corpus *pCorpus);
  virtual void execute();
  virtual void print();

private:
  vector<string> states;
};

#endif // STATE_H_INCLUDED
