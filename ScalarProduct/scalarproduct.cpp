#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
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
        // Flush line with vector size, since we don't use it
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');

        // Read a line and parse into integers
        istream_iterator<Number> eos;
        string line;
        getline(inFile, line);
        istringstream buf(line);
        vector<Number> vec1(istream_iterator<Number>(buf), eos);

        // Read second line into integers
        getline(inFile, line);
        buf.str(line);
        buf.clear();
        vector<Number> vec2(istream_iterator<Number>(buf), eos);

        // Sort one ascending, one descending
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end(), greater<Number>());

        // Taking the inner product of the sorted arrays will give the minimumb
        out << "Case #" << t + 1 << ": "
                << inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0L)
                << endl;
    }

    if(argc > 2)
    {
        ofstream outFile(argv[2]);
        outFile << out;
        outFile.close();
    }
    else
        cout << out.str();

    return 0;
}
