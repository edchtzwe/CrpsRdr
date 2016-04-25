#include "VersionCount.h"

#include <fstream>

VersionCount::VersionCount(string pSystem, Corpus* pCorpus)
{
  corpus = pCorpus;
  system = pSystem;
}

void VersionCount::execute()
{
   ifstream *meta = corpus->getMeta()->getMeta();
//   reset file pointer
   meta->clear();
   meta->seekg(ios::beg);
   int sysvercountIndex = 2; //position of sysvercount in comma separated value file

   while((*meta) >> versionCount){ //read until EOF
      if(versionCount == system){ //found next line
          //skip to the sysvercount row and read the sysvercount
            for(int i = 0; i < sysvercountIndex; ++i){
                  (*meta) >> versionCount;
            }
          break;
      }
   }

   print();
}

void VersionCount::print()
{
  cout<<endl<<"Number of versions for: "<<system<<" is: "<<versionCount<<endl;;
}


