// buses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n, stop_count;
	string command, stop, bus;
	map <string, vector<string>> buses;
	map <string, vector<string>> stops;
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> command;
		if (command == "NEW_BUS") {
			cin >> bus >> stop_count;
			for (int q = 1; q <= stop_count; ++q) {
				cin >> stop;
				buses[bus].push_back(stop);
				stops[stop].push_back(bus);
			}
		}
		else if (command == "BUSES_FOR_STOP") {
			cin >> stop;
			if (stops.count(stop) == 0) { //no stop exists
				cout << "No stop" << endl;
			} else {
				for (auto a : stops[stop]) {
					cout << a << " ";
				}
				cout << endl;
			}
		}
		else if (command == "STOPS_FOR_BUS") {
			cin >> bus;
			if (buses.count(bus) == 0) {
				cout << "No bus" << endl;
			}
			else {
				for (auto a : buses[bus]) {
					cout << "Stop " << a << ": ";
					if (stops[a].size() == 1) { //there is one bus on this stop only
						cout << "no interchange" << endl;
					}
					else {
						for (auto b : stops[a]) {
							if (b != bus) {
								cout << b << " ";
							}
						}
						cout << endl;
					}
				}
			}
		}
		else if (command == "ALL_BUSES") {
			if (buses.size() == 0) {
				cout << "No buses" << endl;
			}
			else {
				for (auto a : buses) {
					cout << "Bus " << a.first << ": ";
					for (auto b : buses[a.first]) {
						cout << b << " ";
					}
					cout << endl;
				}
			}
		}

	}

	return 0;
}

