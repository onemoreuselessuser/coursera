// set1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>

using namespace std;


int main()
{
	int n;
	string command, word1, word2;
	//set <string> input_words;
	set<set<string>>dict;
	map<string, int> words;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> command;
		if (command == "ADD") {
			cin >> word1 >> word2;
			if (dict.count(set<string>{ word1, word2 }) == 0) {
				dict.insert(set<string>{ word1, word2 });
				++words[word1];
				++words[word2];
			}
		}
		else if (command == "CHECK") {
			cin >> word1 >> word2;
			if (dict.count(set<string>{word1, word2}) > 0) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else if (command == "COUNT") {
			cin >> word1;
			cout << words[word1] << endl;
		}

	}
}

