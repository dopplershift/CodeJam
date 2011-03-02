#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <boost/regex.hpp>

#include "CodeSolution.h"

using namespace std;

template <typename InputIterator, typename T>
bool contains(InputIterator first, InputIterator last, const T& value)
{
	return find(first, last, value) != last;
}

template <typename Sequence>
struct Contains : public binary_function<Sequence, char, bool>
{
	bool operator()(Sequence seq, char c)
	{
		return contains(seq.begin(), seq.end(), c);
	}
};

struct ReplaceParens : public unary_function<char, char>
{
	char operator()(char c) const
	{
		if(c == ')')
			return ']';
		else if(c == '(')
			return '[';
		else
			return c;
	}
};

struct RegexMatches : public unary_function<string, bool>
{
	RegexMatches(string pattern)
	{
		transform(pattern.begin(), pattern.end(), pattern.begin(),
				  ReplaceParens());
		exp.set_expression(pattern);
	}

	bool operator()(string word) const
	{
		return boost::regex_match(word, exp);
	}

	boost::regex exp;
};

struct BasicMatches : public unary_function<string, bool>
{
	BasicMatches(string pattern)
	{
		string::iterator it = pattern.begin();
		while(it < pattern.end())
		{
			if(*it == '(')
			{
				string::iterator end = find(it, pattern.end(), ')');
				tokens.push_back(string(it + 1, end));
				it = end + 1;
			}
			else
			{
				tokens.push_back(string(1, *it));
				++it;
			}
		}
	}

	bool operator()(string word) const
	{
		return equal(tokens.begin(), tokens.end(), word.begin(), Contains<string>());
	}

	vector<string> tokens;
};

class AlienLanguageSolution : public CodeSolution
{
public:

	AlienLanguageSolution(bool regex=true) : CodeSolution(), useRegex(regex) {} ;

	virtual void initialRead()
	{
		inFile >> wordLength;
		inFile >> dictSize;
		inFile >> numCases;
		flushLine();

		dict.reserve(dictSize);
		for(unsigned int i=0; i < dictSize; ++i)
			dict.push_back(getLine());
	}

	virtual void solveCase()
	{
		string pattern = getLine();
		if(useRegex)
			out << count_if(dict.begin(), dict.end(), RegexMatches(pattern));
		else
			out << count_if(dict.begin(), dict.end(), BasicMatches(pattern));
	}

private:
	vector<string> dict;
	unsigned int wordLength, dictSize;
	bool useRegex;
};

int main(int argc, const char* argv[])
{
	AlienLanguageSolution als(false);
	return als.process(argc, argv);
}
