/**
*Written by : Chong Tze Wei
**/

#include <boost/regex.hpp>

#include "FieldCount.h"

FieldCount::FieldCount(Version *pVersion)
{
    classInfo = pVersion->getVersion();
//    reset file pointer
    classInfo->clear();
    classInfo->seekg(ios::beg);
    version = pVersion;
}

void FieldCount::execute()
{
string temp;
    int i = 0;
    while(true) {
//            find the position of the class size in the csv
        getline((*classInfo), temp, ',');
        if(temp == "#Fields"){
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
//                go to #Fields row
            for(int j = 0; j < i; ++j){
               getline((*classInfo), temp, ',');
            }
            fields.push_back(temp);
        }
    }

    FieldCount::print();
}

void FieldCount::print()
{
    cout<<endl<<"Showing total number of fields of classes under version "<<version->getVerName()<<endl;

    for(int i = 0; i < fields.size(); ++i) {
        cout<<i+1<<": "<<fields[i]<<endl;
    }
}
