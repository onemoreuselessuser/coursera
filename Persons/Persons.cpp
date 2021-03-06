﻿// Persons.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
	string name;  // изначально имя неизвестно

				  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
	for (const auto& item : names) {
		// если очередной год не больше данного, обновляем имя
		if (item.first <= year) {
			name = item.second;
		}
		else {
			// иначе пора остановиться, так как эта запись и все последующие относятся к будущему
			break;
		}
	}

	return name;
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		last_names[year] = last_name;
	}
	string GetFullName(int year) {
		// получаем имя и фамилию по состоянию на год year
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);

		// если и имя, и фамилия неизвестны
		if (first_name.empty() && last_name.empty()) {
			return "Incognito";

			// если неизвестно только имя
		}
		else if (first_name.empty()) {
			return last_name + " with unknown first name";

			// если неизвестна только фамилия
		}
		else if (last_name.empty()) {
			return first_name + " with unknown last name";

			// если известны и имя, и фамилия
		}
		else {
			return first_name + " " + last_name;
		}
	}


	string GetFullNameWithHistory(int year) {
		vector<string> FName;
		vector<string> LName;
		string resFname;
		string resLname;
		string prevFname;
		string prevLname;


		for (const auto& item : first_names) {
			if (item.first > year) {
				break;
			}
			if (item.second != prevFname) {
				FName.push_back(item.second);
				prevFname = item.second;
			}
		}
		
		for (const auto& item : last_names) {
			if (item.first > year) {
				break;
			}
			if (item.second != prevLname) {
				LName.push_back(item.second);
				prevLname = item.second;
			}
		}
		reverse(begin(FName), end(FName));
		reverse(begin(LName), end(LName));

		if (FName.size() == 0 && LName.size() == 0) {
			return "Incognito";
		}

		if (FName.size() == 0) {
						for (int i = 1; i <= LName.size() - 1; ++i) {
				resLname = resLname + (resLname == "" ? "" : ", ") + LName[i];
			}

			resLname = LName[0] +  (resLname == "" ? "" : " (" + resLname + ")");
			return resLname + " with unknown first name";

		}
		
		if (LName.size() == 0) {
			for (int i = 1; i <= FName.size() - 1; ++i) {
				resFname = resFname + (resFname == "" ? "" : ", ") + FName[i];
			}

			resFname = FName[0] + (resFname == "" ? "" :  " (" + resFname + ")");
			return resFname + " with unknown last name";

		}


		for (int i = 1; i <= LName.size() - 1; ++i) {
			resLname = resLname + (resLname == "" ? "" : ", ") + LName[i];
		}

		resLname = LName[0] + (resLname == "" ? "" : " (" + resLname + ")");
		for (int i = 1; i <= FName.size() - 1; ++i) {
			resFname = resFname + (resFname == "" ? "" : ", ") + FName[i];
		}

		resFname = FName[0] + (resFname == "" ? "" : " (" + resFname + ")");


		return resFname + " " + resLname;


		/*
		else if (resFname == "") {
			resLname = 
			
			return resLname + " with unknow first name";
		}
		else if (resLname == "") {
			return resFname + " with unknown last name";
		}
		else {
			return resFname + resLname;
		}
		

		return "";

		*/


	}


private:
	map<int, string> first_names;
	map<int, string> last_names;
};

int main()
{
	Person person;

	

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}

