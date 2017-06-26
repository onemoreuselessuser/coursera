// alg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

string ReturnLower(const string& st) {
	string res = "";

	for (auto& i : st) {
		if (isdigit(i)) {
			res += i;
		}
		else {
			res += tolower(i);
		}
	}
	return res;

}

int main()
{
	string s;
	s += "Hello";
	{
		s += " world";
	}
	cout << s;
	/*int n;
	cin >> n;
	
	vector<string> words(n);

	
	for (string& i : words) {
		cin >> i;
	}
	sort(begin(words), end(words), 
		[](string l, string r) {
		return (ReturnLower(l) < ReturnLower(r));
	});

	for (auto& i : words) {
		cout << i << " ";
	}*/
	return 0;
}

