#include "Corpus.h"

Corpus::Corpus(string pPath)
{
    path = pPath;
    loadMeta();
}

void Corpus::loadMeta()
{
//gets a file stream to the metadata file
    metadata = new Metadata(path);
    //ask the metadata to load the summary comma separated value file.
    metadata->loadMeta();
}

Metadata* Corpus::getMeta()
{
    return metadata;
}


void Corpus::destroy()
{
    delete metadata;
}
