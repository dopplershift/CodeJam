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

typedef long long Number;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cerr << "Need to specify input file." << endl;
        exit(EXIT_FAILURE);
    }

    // Stream for saving output.
    ostringstream out;

    ifstream inFile(argv[1]);
    if(!inFile)
    {
        cerr << "Error opening file: " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }

    unsigned int numCases;
    inFile >> numCases;

    // Flush trailing newline
    inFile.ignore(numeric_limits<streamsize>::max(),'\n');

    for(unsigned int t = 0; t < numCases; ++t)
    {
        // Read a line and parse into stringss
        istream_iterator<string> eos;
        string line;
        getline(inFile, line);
        istringstream buf(line);
        vector<string> vec1(istream_iterator<string>(buf), eos);

        // Reverse
        reverse(vec1.begin(), vec1.end());

        // Write out case #
        out << "Case #" << t + 1 << ": ";

        // Write out words separated by spaces
        copy(vec1.begin(), vec1.end(), ostream_iterator<string>(out, " "));
        out << endl;
    }

    // If we've been given an extra parameter, use this as the filename
    // to write output to. Otherwise, just dump to standard out.
    if(argc > 2)
    {
        ofstream outFile(argv[2]);
        outFile << out.str();
        outFile.close();
    }
    else
        cout << out.str();

    return 0;
}
