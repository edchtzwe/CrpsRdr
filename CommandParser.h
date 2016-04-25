/**
*Written by : Chong Tze Wei
**/

#ifndef COMMANDPARSER_H_INCLUDED
#define COMMANDPARSER_H_INCLUDED

#include <vector>
#include <fstream>

#include "CorpusLoader.h"
#include "Corpus.h"
#include "Version.h"
using namespace std;

/**
*gets the user input, parses it, validates it and initializes the qualitas
*that is queried
**/

class CommandParser
{
  public:
    /**splits the cmd line args**/
    CommandParser(int argc, char **argv);
    /**releases resources**/
    void destroy();

    /**validate arguments**/
    bool validateMetric();
    bool validateQuery(string query);

    /**determines the metric requested and makes an object of the type**/
    void createMetric();
    /**creates a corpus object**/
    void createCorpus();
    /**executes the queries**/
    void execute();

    /**accessors**/
    string getMetric() const;
    string getPath() const;
    string getSystem() const;
    string getCurrQuery(); //gets the 1st item on the query list (pops it)
    Corpus* getCorpus();

  private:
    string metric; //name of the corpus. eg. corpus
    string path; //path to root folder of metric
    string system; //system to query in system metrics
    string version; ////if "none", we're looking at system metrics
    vector<string> queries; //collection of queries to execute

    Corpus *corpus; //corpus object
    CorpusLoader *corpusLoader;
    Version *verObj;
};

#endif // COMMANDPARSER_H_INCLUDED
