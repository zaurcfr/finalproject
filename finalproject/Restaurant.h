#pragma once
#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include "AdminClient.h"
using namespace std;

class Restaurant {
	string name;
	string address;
	string city;
	double budget;
	list<Admin> admins;
public:
	Restaurant() :name(""), address(""), city(""), budget(0) {}
	Restaurant(const string& name, const string& address, const string& city, const double& budget) {
		setName(name);
		setAddress(address);
		setCity(city);
		setBudget(budget);
	}

	string getName()const {
		return name;
	}
	void setName(const string& name) {
		if (!name.empty()) this->name = name;
	}
	string getAddress()const {
		return address;
	}
	void setAddress(const string& address) {
		if (!address.empty()) this->address = address;
	}
	string getCity()const {
		return city;
	}
	void setCity(const string& city) {
		if (!city.empty()) this->city = city;
	}
	double getBudget()const {
		return budget;
	}
	void setBudget(const double& budget) {
		if (budget > 0) this->budget = budget;
	}

	friend ostream& operator<<(ostream& out, const Restaurant& restaurant);
};

ostream& operator<<(ostream& out, const Restaurant& restaurant) {
	out << "\t\t\t\t\t\t\t\t\t\tWelcome to " << restaurant.getName() << endl;
	out << "\t\t\t\t\t\t\t\t\t\tAddress: " << restaurant.getAddress() << endl;
	out << "\t\t\t\t\t\t\t\t\t\tCity: " << restaurant.getCity() << endl;
	out << "\t\t\t\t\t\t\t\t\t\tBudget: " << restaurant.getBudget() << endl;
	return out;
}

void printMenu(const Restaurant& r) {
	cout << setw(100) << right << r.getName() << "'ya xosh geldiniz" << endl;
	cout << setw(95) << right << "Address: " << r.getAddress() << endl;
	cout << setw(92) << right << "City: " << r.getCity() << endl;
	cout << "Admin yoxsa Musteri kimi davam etmek isteyirsiniz ? 1 ve ya 2 secin." << endl;
	cout << "1. Musteri" << endl;
	cout << "2. Admin" << endl;
}
