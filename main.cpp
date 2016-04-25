#include <iostream>
//#include <boost/regex.hpp>

#include "CommandParser.h"
#include "Corpus.h"
#include "Metadata.h"

using namespace std;

int main(int argc, char **argv)
{
    CommandParser *cmdParser = new CommandParser(argc, argv);
    //open the summary.csv comma separated value file
    cmdParser->createMetric();

    //execute the queries
    cmdParser->execute();

    delete cmdParser;

    return 0;
}
