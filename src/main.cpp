#include <iostream>
using std::cout;
using std::endl;

#include "../h/Index.h"
#include "../h/stringHelpers.h"

int main(int argc, char** argv)
{
	//index.addTextFilesInDirectory("/home/william/mscl/linux-4.8.10/");
	index.addTextFilesInDirectory(".");
	
	
	
	//index.addFile("src/main.cpp");
	//index.addFile("testSearchFile.txt");
	
	cout << "searching.." << endl;
	
	vector<RangeInFile> results;
	
	//index.searchFor("part->elements[i] != FLEX_ARRAY_FREE", results);
	index.searchFor("include", results);
	
	cout << "results:" << endl;
	
	for (auto i: results)
	{
		string labelString;
		
		labelString+=i.getFile()->getFilepath();
		labelString+=" line ";
		labelString+=std::to_string(i.getLineNumber());
		
		cout << putStringInBox(i.getLineString(), false, labelString) << endl;
	}
}
