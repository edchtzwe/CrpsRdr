#ifndef CORPUS_H_INCLUDED
#define CORPUS_H_INCLUDED

#include <iostream>

#include "Metadata.h"
using namespace std;

/**
*A corpus qualitas. It holds the metadata(summary.csv) of all systems
*under the corpus qualitas
*This is linked from CorpusLoader and next link would be
*Metadata
**/

class Corpus
{
    public:
    /**constructor
    *gets the directory of the system specified
    **/
    Corpus(string pPath);
    void destroy();
    /**reads the metadata**/
    void loadMeta();

    /**accessor**/
    Metadata* getMeta();

    private:
    string path; //path to the metadata summary.csv
    Metadata *metadata; //contains an ifstream to summary.csv
};

#endif // CORPUS_H_INCLUDED
