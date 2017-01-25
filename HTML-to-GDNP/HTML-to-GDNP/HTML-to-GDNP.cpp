// HTML-to-GDNP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	// Open the file for reading
	ifstream ifile{ argv[1] };

	if (!ifile)
	{
		cerr << "Failed to open the file" << endl;
		exit(1);
	}
	
	// Define regex's
	regex regexNote{ "\\[!NOTE\\]" };
	regex regexImg{ "src=\"/resources/images\en-us/(?<foo>.+)\\.png\"" };

	// Copy contents of file into buffer
	string output{ "[!NOTE] hello world src=\"resources/images/en-us/bar.png\"" };

	//while (ifile)
	//{
	//	string buffer;
	//	getline(ifile, buffer);
	//	output.append(buffer);
	//	output.append("\n");
	//}
	//
	// Search for regex's and replace
	output = regex_replace(output, regexNote, "<strong>Note</strong>");
	
	

	// Move to beginning of file
	ifile.seekg(0, ios::beg);

	// Read tokens from the file into the buffer
	//while (ifile)
	//{
	//	string buffer;
	//	ifile >> buffer;
	//	if (buffer.substr(0, 28) == R"(src="/resources/images/en-us/)")	// Raw string: R"(string)"
	//	{
	//		char c{ buffer.at(29) };
	//		string imageName{ "" };
	//		while (c != '.')
	//		{
	//			imageName += c;
	//		}
	//		string newImageName{ "/en-us/windows/documentation/PublishingImages/" + imageName + ".png" };

	//	}
	//}

	// Create new file and output buffer to it
	ofstream ofile{ "new.html" };
	ofile << output;

    return 0;
}

