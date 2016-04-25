/**
*Written by : Chong Tze Wei
**/

#include "ClassName.h"

ClassName::ClassName(Version *pVersion)
{
//    get file path to version file
    classInfo = pVersion->getVersion();
//    reset file pointer
    classInfo->clear();
    classInfo->seekg(ios::beg);
//    make alias for the version pointer
    version = pVersion;
}

void ClassName::execute()
{
    string temp; //data holder
    int i = 0; //used to keep track of where the class name index is in the comma separated value file.
    while(true) {
//            find the position of the class name in the csv
        getline((*classInfo), temp, ',');
        if(temp == "ClassName"){
                break;
        }
        ++i;
    }

//get the index from the position
    --i;

//read until EOF
    while(getline((*classInfo), temp, ',')) {
//            found head of line
        if(temp == version->getVerName()) {
//                go to class names row
            for(int j = 0; j < i; ++j){
               getline((*classInfo), temp, ',');
            }
            names.push_back(temp);
        }
    }


    ClassName::print();
}

void ClassName::print()
{
    cout<<endl<<"The names of all classes under version "<<version->getVerName()<<endl;

    for(int i = 0; i < names.size(); ++i) {
        cout<<i+1<<": "<<names[i]<<endl;
    }
}
