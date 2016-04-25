#include "State.h"

State::State(string pSystem, Corpus *pCorpus)
{
    system = pSystem;
    corpus = pCorpus;
}

void State::execute()
{
    ifstream *meta = corpus->getMeta()->getMeta();
//    clear file pointer
    meta->clear();
    meta->seekg(ios::beg);

    string _temp;

    while((*meta) >> _temp) { //read until EOF
        if(_temp == system) { //found head of line (next line)
            (*meta) >> _temp;
            states.push_back(_temp);
        }
    }



    print();
}

void State::print()
{
  cout<<endl<<"Status of all versions of system "<<system<<endl;

  for(int i = 0; i < states.size(); ++i){
      cout<<i+1<<": "<<states[i]<<endl;
  }
}
