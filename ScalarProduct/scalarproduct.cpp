#include "CodeSolution.h"

#include <algorithm>
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
        unsigned int vecSize = lineValue<unsigned int>();

        // Read 2 lines and parse into integers
        vector<Number> vec1 = lineToVector<Number>(vecSize);
        vector<Number> vec2 = lineToVector<Number>(vecSize);

        // Sort one ascending, one descending
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end(), greater<Number>());

        // Taking the inner product of the sorted arrays will give the minimum
        out << inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0L);
    }
};

int main(int argc, const char* argv[])
{
    ScalarProductSolution sps;
    return sps.process(argc, argv);
}
