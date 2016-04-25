#ifndef METADATA_H_INCLUDED
#define METADATA_H_INCLUDED

#include <iostream>
#include <fstream>
using namespace std;

/**
*contains a stream to the metadata file
*This is linked from Corpus and is the end of the chain
**/

class Metadata
{
    public:
    /**constructor**/
    Metadata(string pPath);
    void destroy();
    /**loads the metadata**/
    void loadMeta();

    /**accessors**/
    ifstream* getMeta() const;

    private:
    /**opens a stream to access the metadata file as needed
    *saves space, since we don't need to store everything on memory and
    *writing to a file may need special permission from an admin.
    **/
    ifstream *metaFile;
    /**path to metadata file summary.csv**/
    string path;
};

#endif // METADATA_H_INCLUDED
