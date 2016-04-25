/**
*Written by : Chong Tze Wei
**/

#include "ClassSize.h"

ClassSize::ClassSize(Version *pVersion)
{
//    get stream to file to work on
    classInfo = pVersion->getVersion();
//    reset file pointer
    classInfo->clear();
    classInfo->seekg(ios::beg);
//    alias to the version object in memory
    version = pVersion;
}

void ClassSize::execute()
{
    string temp; //data holder
    int i = 0; //index of class size in the comma separated value file
    while(true) {
//            find the position of the class size in the csv
        getline((*classInfo), temp, ',');
        if(temp == "#Bytes"){
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
//                go to class size row
            for(int j = 0; j < i; ++j){
               getline((*classInfo), temp, ',');
            }
            sizes.push_back(temp);
        }
    }


    ClassSize::print();
}

void ClassSize::print()
{
    cout<<endl<<"Sizes of all classes under version "<<version->getVerName()<<endl;

    for(int i = 0; i < sizes.size(); ++i) {
        cout<<i+1<<": "<<sizes[i]<<endl;
    }
}
