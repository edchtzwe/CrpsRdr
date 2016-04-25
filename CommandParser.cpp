/**
*Written by : Chong Tze Wei
**/

#include <cstdlib>

#include "CommandParser.h"
#include "SystemMetrics.h"
#include "VersionCount.h"
#include "ReleaseDates.h"
#include "State.h"
#include "ClassName.h"
#include "ClassSize.h"
#include "FieldCount.h"

CommandParser::CommandParser(int argc, char **argv)
{
    /**to keep track of which argv index does the 1st query start**/
    int index = 1;
    /**in c++, argv[0] is the name of the program**/
    metric = argv[index];
    validateMetric();
    ++index;
    path = argv[index];
//    skip "index"
    index += 2;
    system = argv[index];
    ++index;
//    see if we are looking at a version metric query
    string _version = "version";
    if(argv[index] == _version) { //version metric query
        ++index;
        version = argv[index];
        ++index;
    } else { //system metric query
        version = "none";
    }

//store queries for processing later
    for(index; index < argc; ++index) {
        queries.push_back(argv[index]);
    }
}

bool CommandParser::validateMetric()
{
    string _qualitas[] = {"corpus"};
    int _qsize = 1; //size of the qualitas array, client envisage that other qualitas will be added later

    bool _ok = false;

//check input
    for(int i = 0; i < _qsize; ++i) {
        if(metric == _qualitas[i]) {
            _ok = true;
        }
    }

    if(_ok == false) {
        cerr<<"INVALID QUALITAS. QUIT.";
        exit(1);
    }

    return _ok; //return, in case I don't want to straight out quit the program next time

}

bool CommandParser::validateQuery(string query)
{
    string _sysActions[] = {"count_versions", "release-dates", "full-names"};
    int _sasize = 3; //size of the sysActions array

    bool _ok = false;

//validate query
    for(int i = 0; i < _sasize; ++i) {
        if(query == _sysActions[i]) {
            _ok = true;
        }
    }

    if(_ok == false) {
        cerr<<"INVALID COMMAND. QUIT";
        exit(1);
    }

    return _ok;
}


void CommandParser::createMetric()
{
//    factory method
    string _corpus = "corpus";
    if(getMetric() == _corpus) {
        createCorpus();
    }
}

void CommandParser::createCorpus()
{
//create a corpus object using CorpusLoader
    corpusLoader = new CorpusLoader(getPath());
    corpus = corpusLoader->getCorpus();
}

void CommandParser::execute()
{
//    system metrics
    if(version == "none") {
        string _sysActions[] = {"count-versions", "release-dates", "get-status"};
        int _size = queries.size(); //number of queries entered, to do all queries
        for(int i = 0; i < _size; ++i) {
            string _action = getCurrQuery();
            //count versions
            if(_action == _sysActions[0]) {
                VersionCount *versionCount = new VersionCount(system, corpus);
                versionCount->execute();
                delete versionCount;
            } else if(_action == _sysActions[1]) { //release dates
                ReleaseDates *releaseDates = new ReleaseDates(system, corpus);
                releaseDates->execute();
                delete releaseDates;
            } else if(_action == _sysActions[2]) { //get-status
                State *state = new State(system, corpus);
                state->execute();
                delete state;
            } else {
                cout<<"Invalid input";
                exit(1);
            }
        }
    } else { //version metrics
        verObj = new Version(path, system, version);
        string _verActions[] = {"get-names", "class-size", "field-count"};
        int _size = queries.size();

        for(int i = 0; i < _size; ++i) {
            string _action = getCurrQuery();
            if(_action == _verActions[0]) { //get-names
                ClassName *className = new ClassName(verObj);
                className->execute();
                delete className;
            } else if(_action == _verActions[1]) { //class-size
                ClassSize *classSize = new ClassSize(verObj);
                classSize->execute();
                delete classSize;
            } else if(_action == _verActions[2]) { //field-count
                FieldCount *fieldCount = new FieldCount(verObj);
                fieldCount->execute();
                delete fieldCount;
            } else {
                cout<<"Invalid input";
                exit(1);
            }
        }
    }
}


/**accessors**/

string CommandParser::getPath() const
{
    return path;
}

string CommandParser::getMetric() const
{
    return metric;
}

Corpus* CommandParser::getCorpus()
{
    return corpus;
}

string CommandParser::getCurrQuery()
{
    //simulate pop-front
    string _query = queries[0];
    queries.erase(queries.begin());

    return _query;
}


void CommandParser::destroy()
{
    corpus->getMeta()->destroy();
    corpus->destroy();
    delete corpusLoader;
    delete corpus;
}
