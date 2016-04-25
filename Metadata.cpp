#include "Metadata.h"
#include <cstdlib>

Metadata::Metadata(string pPath)
{
  path = pPath;
}

void Metadata::loadMeta()
{
  metaFile = new ifstream();
  metaFile->open(path.c_str()); //open the metadata file which is summary.csv
  if(metaFile->is_open() == false){
      cerr<<"FILE NOT FOUND. QUIT";
      exit(1);
  }
}

ifstream* Metadata::getMeta() const
{
  return metaFile;
}

void Metadata::destroy()
{
  (*metaFile).close();
  delete metaFile;
}
