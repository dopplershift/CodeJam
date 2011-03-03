#include "CodeSolution.h"

#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef pair<int, int> line;

struct intersects : public unary_function<line, bool>
{
    intersects(line l) : myline(l) {};

    bool operator()(const line& other) const
    {
        bool left = myline.first > other.first;
        bool right = myline.second > other.second;
        return (left || right) && !(left && right);
    }

    line myline;
};

class RopeIntranetSolution : public CodeSolution
{
    virtual void solveCase()
    {
        unsigned int numLines = lineValue<int>();
        vector<line> lines;
        for(unsigned int i=0; i < numLines; ++i)
        {
            int left, right;
            inFile >> left >> right;
            flushLine();
            lines.push_back(line(left, right));
        }

        unsigned int total = 0;
        for(vector<line>::iterator it=lines.begin(); it != lines.end(); ++it)
            total += count_if(it + 1, lines.end(), intersects(*it));

        out << total;
    }
};

int main(int argc, const char* argv[])
{
    RopeIntranetSolution ris;
    return ris.process(argc, argv);
}
