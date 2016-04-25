#include "ReleaseDates.h"

#include <boost/regex.hpp>

ReleaseDates::ReleaseDates(string pSystem, Corpus *pCorpus)
{
    system = pSystem;
    corpus = pCorpus;
}

void ReleaseDates::execute()
{
    ifstream *meta = corpus->getMeta()->getMeta();
//    reset file pointer
    meta->clear();
    meta->seekg(ios::beg);

  string _temp; //data holder

  while((*meta) >> _temp){
    if(_temp == system){ //found head of line (next line)
        while((*meta) >> _temp){
            char *ptrn = "\\d{4}-\\d{2}-\\d{2}"; //pattern for the date format
            boost::regex exp(ptrn);
            boost::cmatch what;
//regular expression matching
            if(boost::regex_search(_temp.c_str(), what, exp) == true){
                dates.push_back(string(what[0].first, what[0].second)); //found the date, add to vector
                break;
            }
        }
    }
  }

    print();
}

void ReleaseDates::print()
{
    cout<<endl<<"Release dates of all versions of "<<system<<endl;

    for(int i = 0; i < dates.size(); ++i) {
        cout<<i+1<<": "<<dates[i]<<endl;
    }
}
