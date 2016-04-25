/**
*Written by : Chong Tze Wei
**/

#include "Version.h"

#include <cstdlib>

Version::Version(string pPath, string pSystem, string pVersion)
{
//    create the file path to the queried version's class-info.csv file by appending the bits and pieces of queries supplied from the args
    string _path = pPath + "\\Systems\\" + pSystem + "\\" + pVersion + "\\" + "class-info.csv";
//    open up the file stream
    version = new ifstream();
    version->open(_path.c_str());

    //fail safe error handling
    if(version->is_open() == false) {
        cerr<<"FILE NOT FOUND. QUIT";
        exit(1);
    }
    verName = pVersion;
}

ifstream* Version::getVersion()
{
    return version;
}

string Version::getVerName() const
{
    return verName;
}

void Version::destroy()
{
    version->close();
    delete version;
}
