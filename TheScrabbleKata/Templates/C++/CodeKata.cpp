#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void getLines(vector<string>& linesVec_, ifstream& inFile_)
{
	string line;
	while (getline(inFile_, line))
	{
		linesVec_.push_back(line);
	}
}

void printLines(vector<string>& linesVec_)
{
	for (int i = 0; i < linesVec_.size(); ++i)
	{
		cout << linesVec_[i] << "\n";
	}
}

int main(int argc, char* argv[])
{
	if (2 != argc)
	{
		cout << "Wrong argument\nUsage: " << argv[0] << " file\n";
		return 1;
	}
	
	ifstream inFile(argv[1]);
	if (!inFile)
	{
		cout << "Cannot open input file " << argv[1] << "\n";
		return 1;
	}
	
	vector<string> linesVec;
	getLines(linesVec, inFile);
	
	printLines(linesVec);
	
	inFile.close();
	return 0;
}
