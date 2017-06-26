// alg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);

	for (auto& i : nums) {
		cin >> i;
	}
	
	sort(begin(nums), end(nums), [](int i, int j) { return abs(i) < abs(j); });
	
	for (auto& i : nums) {
		cout << i << " ";
	}

	return 0;
}

