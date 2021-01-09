#pragma once
#include <iostream>
#include <string>
using namespace std;


class Person {
private:
	string name;
	string surname;
	int age;
	string phoneNumber;
public:
	Person() :name(""), surname(""), age(0), phoneNumber("") {}
	Person(const string& name, const string& surname, const int& age, const string& phoneNumber)
	{
		setName(name);
		setSurname(surname);
		setAge(age);
		setPhoneNumber(phoneNumber);
	}

	string getName()const {
		return name;
	}
	void setName(const string& name) {
		if (!name.empty()) this->name = name;
	}
	string getSurname()const {
		return surname;
	}
	void setSurname(const string& surname) {
		if (!surname.empty()) this->surname = surname;
	}
	int getAge()const {
		return age;
	}
	void setAge(const int& age) {
		if (age != 0) this->age = age;
	}
	string getPhoneNumber()const {
		return phoneNumber;
	}
	void setPhoneNumber(const string& phoneNumber) {
		if (!phoneNumber.empty()) this->phoneNumber = phoneNumber;
	}

	virtual ~Person() = 0 {}

};

class Admin :public Person {
	string username;
	string password;
public:
	Admin() :username(""), password("") {}
	Admin(const string& name, const string& surname, const int& age, const string& phoneNumber, const string& username, const string& password) :Person(name, surname, age, phoneNumber) {
		setUsername(username);
		setPassword(password);
	}

	string getUsername()const {
		return username;
	}
	void setUsername(const string& username) {
		if (!username.empty()) this->username = username;
	}
	string getPassword()const {
		return password;
	}
	void setPassword(const string& password) {
		if (!password.empty()) this->password = password;
	}

	bool signIN(const string& username, const string& password) {
		if (this->username == username)
		{
			if (this->password == password)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		return 0;
	}


};

class Client :public Person {
	string tableNo;
	double budget;
public:
	Client() :tableNo(""), budget(0) {}
	Client(const string& name, const string& surname, const int& age, const string& phoneNumber, const string& tableNo, const double& budget) :Person(name, surname, age, phoneNumber) {
		setTableNo(tableNo);
		setBudget(budget);
	}

	string getTableNo()const {
		return tableNo;
	}
	void setTableNo(const string& tableNo) {
		if (!tableNo.empty()) this->tableNo = tableNo;
	}
	double getBudget()const {
		return budget;
	}
	void setBudget(const double& budget) {
		if (budget > 0)this->budget = budget;
	}
	friend istream& operator>>(istream& in, Client& client);
};

istream& operator>>(istream& in, Client& client) {
	string name;
	cout << "Adinizi daxil edin: "; in >> name;
	client.setName(name);
	string surname;
	cout << "Soyadinizi daxil edin: "; in >> surname;
	client.setSurname(surname);
	string tableNo;
	cout << "Eyleshdiyiniz masanin nomresini daxil edin: "; in >> tableNo;
	client.setTableNo(tableNo);
	return in;
}
