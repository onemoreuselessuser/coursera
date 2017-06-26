// buses2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;


int main()
{
	int n, bus = 1, stop_count;
	string stop;
	set<string> input_stops;
	cin >> n;

	map<set<string>, int> buses;

	for (int i = 1; i <= n; ++i) {
		cin >> stop_count;
		input_stops.clear();
		for (int q = 1; q <= stop_count; ++q) {
			cin >> stop;
			input_stops.insert(stop);
		}
		if (buses.count(input_stops) == 0) {
			buses[input_stops] = bus;
			++bus;
			cout << "New bus " << buses[input_stops] << endl;
		}
		else {
			cout << "Already exists for " << buses[input_stops] << endl;
		}
	}

    return 0;
}

