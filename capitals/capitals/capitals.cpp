// capitals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
bool CheckIfExists(const map<string, string>& capitals, string country, string capital) {
	for (auto item : capitals) {
		if (capital == "") { //check if country exists

		}
}
}
*/
int main()
{
    
	map<string, string> countries;
	int n;
	string command, worda, wordb;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> command;
		if (command == "CHANGE_CAPITAL") {
			cin >> worda >> wordb; //worda - country  wordb - new_capital 
			
			if (countries.count(worda) == 0) { //country doesn't exist
				countries[worda] = wordb;
				cout << "Introduce new country " << worda << " with capital " << wordb << endl;
			}
			else if (countries.find(worda)->second == wordb) { // country - capital already exist
				cout << "Country " << worda << " hasn't changed its capital" << endl;
			}
			else { //changing capital
				cout << "Country " << worda <<  " has changed its capital from " << countries[worda] << " to " << wordb << endl;
				countries[worda] = wordb;
			}

		}
		else if (command == "RENAME") {
			cin >> worda >> wordb; //worda - old_country wordb - new_country
			if (countries.count(worda) == 0 || countries.count(wordb) > 0 || worda == wordb) { //old country doesn't exist, new country exists or new country = old country
				cout << "Incorrect rename, skip" << endl;
			}
			else {
				cout << "Country " << worda << " with capital " << countries[worda] << " has been renamed to " << wordb << endl;
				countries[wordb] = countries[worda]; //create new country and move capital
				countries.erase(worda); //remove old country
			}
		}
		else if (command == "ABOUT") {
			cin >> worda; //worda - country
			if (countries.count(worda) == 0) {
				cout << "Country " << worda << " doesn't exist" << endl;
			}
			else {
				cout << "Country " << worda << " has capital " << countries[worda] << endl;
			}
		}
		else if (command == "DUMP") {
			if (countries.size() == 0) {
				cout << "There are no countries in the world";
			}
			else {
				for (auto item : countries) {
					cout << item.first << "/" << item.second << " ";
				}
				
			}
			cout << endl;
		}
	}
	
	return 0;
}

