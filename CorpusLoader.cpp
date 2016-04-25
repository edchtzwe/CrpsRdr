#include "CorpusLoader.h"
#include "Metadata.h"

CorpusLoader::CorpusLoader(string pPath)
{
    pPath += "\\metadata\\summary.csv";
    path = pPath;

    locateCorpus();
}

void CorpusLoader::locateCorpus()
{
//    factory method
    corpus = new Corpus(path);
    //ask the corpus to open a file stream to the summary comma separated value file
    corpus->loadMeta();
}

Corpus* CorpusLoader::getCorpus() const
{
    return corpus;
}

void CorpusLoader::destroy()
{

}
