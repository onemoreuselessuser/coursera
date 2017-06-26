// SortedThings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
	void AddString(const string& s) {
		words.push_back(s);
	}
	
	vector<string> GetSortedStrings() {
		sort(begin(words), end(words));
		return words;
	}
private:
	vector<string> words;
};

void PrintSortedStrings(SortedStrings& strings) {
	for (const string& s : strings.GetSortedStrings()) {
		cout << s << " ";
	}
	cout << endl;
}

int main()
{
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
	return 0;
}

