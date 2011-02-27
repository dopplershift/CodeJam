#include "CodeSolution.h"

#include <algorithm>
#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>

using namespace std;

class ScalarProductSolution : public CodeSolution
{
    typedef long long Number;

    void solveCase()
    {
        // Flush line with vector size, since we don't use it
        getLine();

        // Read a line and parse into integers
        istream_iterator<Number> eos;
        istringstream buf(getLine());
        vector<Number> vec1(istream_iterator<Number>(buf), eos);

        // Read second line into integers
        buf.str(getLine());
        buf.clear();
        vector<Number> vec2(istream_iterator<Number>(buf), eos);

        // Sort one ascending, one descending
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end(), greater<Number>());

        // Taking the inner product of the sorted arrays will give the minimum
        out << inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0L);
    }
};

int main(int argc, char* argv[])
{
    ScalarProductSolution sps;
    return sps.process(argc, argv);
}
