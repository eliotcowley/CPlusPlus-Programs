/* 
	X11.cpp : Read a sequence of words from input. Use Quit as a word that terminates the input. Print the words in the
	order they were entered. Don't print a word twice. Modify the program to sort the words before printing them.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// Enter words
	string word;
	vector<string> words;

	while (true)
	{
		cout << "Enter a word: ";
		cin >> word;
		if (word != "Quit")
		{
			words.push_back(word);
		}
		else
		{
			break;
		}
	}

	// Check for dupes
	cout << "Checking for duplicates...\n";
	cout << "Outputting in order...\n";
	vector<string> wordsSoFar;
	bool dupe{ false };

	for (string s1 : words)
	{
		for (string s2 : wordsSoFar)
		{
			if (s1 == s2)
			{
				dupe = true;
				break;
			}
		}
		if (!dupe)
		{
			wordsSoFar.push_back(s1);
			cout << s1 << '\n';
		}
		dupe = false;
	}

	// Sort words (bubble sort)
	cout << "Sorting...\n";
	auto n{ wordsSoFar.size() };
	bool swapped{ true };
	while ((n > 0) && (swapped))
	{
		swapped = false;
		for (int i{ 0 }; i < n-1; i++)
		{
			if (wordsSoFar[i] > wordsSoFar[i + 1])
			{
				swap(wordsSoFar[i], wordsSoFar[i + 1]);
				swapped = true;
			}
		}
		n--;
	}
	cout << "Printing sorted words...\n";
	for (string s : wordsSoFar)
	{
		cout << s << '\n';
	}
	
    return 0;
}

