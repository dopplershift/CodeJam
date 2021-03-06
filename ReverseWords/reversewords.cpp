#include "CodeSolution.h"

#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class ReverseWordsSolution : public CodeSolution
{
    void solveCase()
    {
        // Read a line and parse into strings
        vector<string> vec = lineToVector<string>();

        // Reverse
        reverse(vec.begin(), vec.end());

        // Write out words separated by spaces
        copy(vec.begin(), vec.end(), ostream_iterator<string>(out, " "));
    }
};

int main(int argc, const char* argv[])
{
    ReverseWordsSolution rws;
    return rws.process(argc, argv);
}
