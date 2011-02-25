// TODO: Convert to a class to eliminate boilerplate. This could even be
// a header-only class to eliminate linking problems. Could also create a
// full skeleton project for easy starting a new problem.

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    //
    // Boilerplate commandline and opening input
    //

    // Check commandline
    if(argc < 2)
    {
        cerr << "Need to specify input file." << endl;
        exit(EXIT_FAILURE);
    }

    // Open input file
    ifstream inFile(argv[1]);
    if(!inFile)
    {
        cerr << "Error opening file: " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }

    // Stream for saving output.
    ostringstream out;

    // Read number of cases
    unsigned int numCases;
    inFile >> numCases;

    // Flush trailing newline
    inFile.ignore(numeric_limits<streamsize>::max(),'\n');

    for(unsigned int t = 0; t < numCases; ++t)
    {
        //
        // Begin actual algorithm
        //

        // Read a line and parse into strings
        istream_iterator<string> eos;
        string line;
        getline(inFile, line);
        istringstream buf(line);
        vector<string> vec(istream_iterator<string>(buf), eos);

        // Reverse
        reverse(vec.begin(), vec.end());

        // Write out case #
        out << "Case #" << t + 1 << ": ";

        // Write out words separated by spaces
        copy(vec.begin(), vec.end(), ostream_iterator<string>(out, " "));
        out << endl;
    }

    //
    // More boilerplate output
    //

    // If we've been given an extra parameter, use this as the filename
    // to write output to.
    if(argc > 2)
    {
        ofstream outFile(argv[2]);
        outFile << out.str();
        outFile.close();
    }

    // Also dump output to standard out
    cout << out.str();

    return 0;
}
