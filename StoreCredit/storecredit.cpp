#include "CodeSolution.h"

#include <algorithm>
#include <functional>
#include <vector>

class StoreCreditSolution : public CodeSolution
{
	virtual void solveCase()
	{
		// Read in the information
		int total = lineValue<int>();
		int listSize = lineValue<int>();
		vector<int> list = lineToVector<int>(listSize);
		vector<int>::iterator first, second;

		// Loop over all entries in the list. Look for an item in the rest
		// of the list that is equal to the remainder.
		for(first = list.begin(); first != list.end(); ++first)
		{
			binder1st<equal_to<int> > equal_rest(equal_to<int>(),
												 total - *first);

			// Need to start past the current item so we don't duplicate
			second = find_if(first + 1, list.end(), equal_rest);
			if(second != list.end())
				break;
		}

		// Output expects 1-based indexing, so need to add 1.
		out << distance(list.begin(), first) + 1 << " "
			<< distance(list.begin(), second) + 1;
	}
};

int main(int argc, const char* argv[])
{
	StoreCreditSolution scs;
	return scs.process(argc, argv);
}
