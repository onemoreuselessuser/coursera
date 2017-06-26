// set1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int n;
	string word;
	set<string> unique_words;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> word;
		unique_words.insert(word);
	}
	
	cout << unique_words.size() << endl;
	return 0;
}

