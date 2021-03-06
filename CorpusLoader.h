#ifndef CORPUSLOADER_H_INCLUDED
#define CORPUSLOADER_H_INCLUDED

#include <iostream>

#include "Corpus.h"
using namespace std;

/**
*A utility class that creates a Corpus object
*this is the start of the link which goes to Corpus
**/

class CorpusLoader
{
    public:
    /**constructor to set the path(from args) field**/
    CorpusLoader(string pPath);
    void destroy();
    /**calls corpus class, get the corpus following the path**/
    void locateCorpus();
    /**if we are looking for version metrics
    *gets the version of the system we are looking for
    *based on the version number passed in as cmd line args
    **/
    void loadVersion();

    /**accessors**/
    Corpus* getCorpus() const;

    private:
    /**file path to the corpus metadata**/
    string path;
    /**a corpus object, to be passed back to CommandParser**/
    Corpus *corpus;
};

#endif // CORPUSLOADER_H_INCLUDED
