#ifndef CODESOLUTION_H
#define CODESOLUTION_H

#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class IOError: public exception
{
  virtual const char* what() const throw()
  {
	return "Error in I/O";
  }
} IOErr;


class CodeSolution
{
public:
	~CodeSolution();

	int process(int argc, const char* argv[]);
	void run();

protected:
	// Basic functionality
	void open(int argc, const char* argv[]);

	// Useful helpers
	string getLine();
	template<typename T> void lineToVector(vector<T>& vec, size_t n=0);
	template<typename T> vector<T> lineToVector(size_t n=0);
	template<typename T> T lineValue();
	void flushLine();

	virtual void initialRead();
	virtual void solveCase() = 0;
	ostringstream out;
	unsigned int numCases;
	ifstream inFile;

private:
	ofstream outFile;
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

int CodeSolution::process(int argc, const char *argv[])
{
	open(argc, argv);
	run();
	return 0;
}

void CodeSolution::open(int argc, const char *argv[])
{
	// Check commandline
	if(argc < 2)
	{
		cerr << "Need to specify input file." << endl;
		throw IOErr;
	}

	// Open input file
	inFile.open(argv[1]);
	if(!inFile)
	{
		cerr << "Error opening file." << endl;
		throw IOErr;
	}

	// If we were given a second argument on the commandline, use it as an
	// output file.
	if(argc > 2)
		outFile.open(argv[2]);
}

void CodeSolution::run()
{
	// Start by reading the number of cases
	initialRead();

	for(unsigned int t = 0; t < numCases; ++t)
	{
		// Write out case #
		out << "Case #" << t + 1 << ": ";
		solveCase();
		out << endl;
	}
}

void CodeSolution::initialRead()
{
	numCases = lineValue<int>();
}

void CodeSolution::flushLine()
{
	// Flush up to next newline
	inFile.ignore(numeric_limits<streamsize>::max(),'\n');
}

string CodeSolution::getLine()
{
	string line;
	getline(inFile, line);
	return line;
}

template<typename T> T CodeSolution::lineValue()
{
	T value;
	istringstream buf(getLine());
	buf >> value;
	return value;
}

template<typename T> void CodeSolution::lineToVector(vector<T>& vec, size_t n)
{
	if(n > 0)
		vec.reserve(n);
	istream_iterator<T> eos;
	istringstream buf(getLine());
	vec.insert(vec.end(), istream_iterator<T>(buf), eos);
}

template<typename T> vector<T> CodeSolution::lineToVector(size_t n)
{
	vector<T> vec;
	lineToVector(vec, n);
	return vec;
}

#endif // CODESOLUTION_H
