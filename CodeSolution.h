#ifndef CODESOLUTION_H
#define CODESOLUTION_H

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

class CodeSolution
{
public:
    ~CodeSolution();

    int process(int argc, char* argv[]);
    void run();

protected:
    void getNumCases();
    string getLine();
    void open(int argc, char* argv[]);

    virtual void solveCase() = 0;
    ostringstream out;

private:
    ifstream inFile;
    ofstream outFile;
    unsigned int numCases;
};

CodeSolution::~CodeSolution()
{
    // Write the output to the file if necessary
    if(outFile)
    {
        outFile << out.str();
        outFile.close();
    }

    // Also dump output to standard out
    cout << out.str();
}

int CodeSolution::process(int argc, char *argv[])
{
    open(argc, argv);
    run();
    return 0;
}

void CodeSolution::open(int argc, char *argv[])
{
    // Check commandline
    if(argc < 2)
        throw "Need to specify input file.";

    // Open input file
    inFile.open(argv[1]);
    if(!inFile)
        throw "Error opening file.";

    // If we were given a second argument on the commandline, use it as an
    // output file.
    if(argc > 2)
        outFile.open(argv[2]);
}

void CodeSolution::run()
{
    // Start by reading the number of cases
    getNumCases();

    for(unsigned int t = 0; t < numCases; ++t)
    {
        // Write out case #
        out << "Case #" << t + 1 << ": ";
        solveCase();
        out << endl;
    }
}

void CodeSolution::getNumCases()
{
    inFile >> numCases;

    // Flush trailing newline
    inFile.ignore(numeric_limits<streamsize>::max(),'\n');
}

string CodeSolution::getLine()
{
    string line;
    getline(inFile, line);
    return line;
}

#endif // CODESOLUTION_H
