#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

class Meal {
	int myID;
	string name;
	string category;
	double rating;
	double price;
	double tax;
public:
	static int ID;
	Meal() :name(""), category(""), rating(0), price(0), tax(0) {}
	Meal(const string& name, const string& category, const double& rating, const double& price, const double& tax) {
		setID();
		setName(name);
		setCategory(category);
		setRating(rating);
		setPrice(price);
		setTax(tax);
	}

	int getID() {
		return myID;
	}
	void setID() {
		this->myID = ID++;
	}
	string getName()const {
		return name;
	}
	void setName(const string& name) {
		if (!name.empty()) this->name = name;
	}
	string getCategory()const {
		return category;
	}
	void setCategory(const string& category) {
		if (!category.empty()) this->category = category;
	}
	double getRating()const {
		return rating;
	}
	void setRating(const double& rating) {
		if (rating != 0) this->rating = rating;
	}
	double getPrice()const {
		return price;
	}
	void setPrice(const double& price) {
		if (price != 0) this->price = price;
	}
	double getTax()const {
		return tax;
	}
	void setTax(const double& tax) {
		if (tax != 0) this->tax = tax;
	}

	Meal& operator++() {
		this->rating += 0.1;
		return *this;
	}
	Meal operator++(int) {
		Meal temp = *this;
		this->rating += 0.1;
		return temp;
	}
	Meal& operator--() {
		this->rating -= 0.1;
		return *this;
	}
	Meal operator--(int) {
		Meal temp = *this;
		this->rating -= 0.1;
		return temp;
	}

	bool operator==(const Meal& meal)const {
		return meal.getName() == getName();
	}

	void dataWriteToFileMeal(string filename, string name, string category, double rating, double price, double tax) {
		ofstream fout(filename, ios_base::app);
		if (fout.is_open())
		{
			fout << "Name: " << name << endl;
			fout << "Category: " << category << endl;
			fout << "Rating: " << rating << endl;
			fout << "Price: $" << price << endl;
			fout << "Tax: %" << tax << endl;
			fout << "========================================================" << endl;

		}
		fout << "========================================================" << endl;
		fout.close();
	}

	string getDataFromFileMeal(const string& filename) {
		ifstream fin(filename, ios::in);
		string result = "";
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		else
		{
			throw string("This file: " + filename + " does not exists. Error time: " + __TIMESTAMP__);
		}
		return result;
	}

	virtual void showMeal() {
		cout << "=====================================" << endl;
		cout << "ID: " << this->myID << endl;
		cout << "Name: " << getName() << endl;
		cout << "Category: " << getCategory() << endl;
		cout << "Rating: " << getRating() << endl;
		cout << "Price: $" << getPrice() << endl;
		cout << "Tax: %" << getTax() << endl;
	}

	~Meal() {}
};

int Meal::ID = 0;

class Salad :public Meal {
public:
	Salad() = delete;
	Salad(const string& name, const string& category, const double& rating, const double& price, const double& tax) :Meal(name, category, rating, price, tax) {

	}
	void showMeal()override {
		Meal::showMeal();
	}
};
class MainDish :public Meal {
public:
	MainDish() = delete;
	MainDish(const string& name, const string& category, const double& rating, const double& price, const double& tax) :Meal(name, category, rating, price, tax) {

	}
	void showMeal()override {
		Meal::showMeal();
	}
};
class FastFood :public Meal {
public:
	FastFood() = delete;
	FastFood(const string& name, const string& category, const double& rating, const double& price, const double& tax) :Meal(name, category, rating, price, tax) {

	}
	void showMeal()override {
		Meal::showMeal();
	}
};
class Dessert :public Meal {
public:
	Dessert() = delete;
	Dessert(const string& name, const string& category, const double& rating, const double& price, const double& tax) :Meal(name, category, rating, price, tax) {

	}
	void showMeal()override {
		Meal::showMeal();
	}
};


class byNameMeal {
	string order;
public:
	byNameMeal(string order) :order(order) {}

	bool operator()(const Meal& a, const Meal& b) {
		if (order == "Asc") return a.getName() < b.getName();
		else if (order == "Desc") return a.getName() > b.getName();
	}
};
class byRatingMeal {
	string order;
public:
	byRatingMeal(string order) :order(order) {}

	bool operator()(const Meal& a, const Meal& b) {
		if (order == "Asc") return a.getRating() < b.getRating();
		else if (order == "Desc") return a.getRating() > b.getRating();
	}
};
class byPriceMeal {
	string order;
public:
	byPriceMeal(string order) :order(order) {}

	bool operator()(const Meal& a, const Meal& b) {
		if (order == "Asc") return a.getPrice() < b.getPrice();
		else if (order == "Desc") return a.getPrice() > b.getPrice();
	}
};
class byTaxMeal {
	string order;
public:
	byTaxMeal(string order) :order(order) {}

	bool operator()(const Meal& a, const Meal& b) {
		if (order == "Asc") return a.getTax() < b.getTax();
		else if (order == "Desc") return a.getTax() > b.getTax();
	}
};

class Kitchen {
	list<Meal> meals;
	list<Salad> salads;
	list<MainDish> mainDishes;
	list<FastFood> fastFoods;
	list<Dessert> desserts;
	list<Meal> orders;
	Stock stock;
public:
	Kitchen() {
		Salad s1("Caesar", "Salad", 6.9, 8, 5);
		Salad s2("Chicken salad", "Salad", 7.9, 3, 5);
		Salad s3("Crab salad", "Salad", 8.4, 5, 5);
		MainDish m1("Beef Wellington", "Main dish", 8.7, 20, 5);
		MainDish m2("Spaghetti", "Main dish", 9.0, 7, 5);
		MainDish m3("Nachos", "Main dish", 9.1, 12, 5);
		MainDish m4("Ribeye Steak", "Main dish", 9.3, 18, 5);
		FastFood f1("Pizza", "Fast Food", 9.2, 12, 5);
		FastFood f2("Burger", "Fast Food", 8.5, 6, 5);
		FastFood f3("CheeseBurger", "Fast Food", 9.2, 7.5, 5);
		FastFood f4("Marco's Special Burger", "Fast Food", 9.2, 9, 5);
		Dessert d1("Cheesecake", "Dessert", 8.8, 3, 5);
		Dessert d2("Croissant", "Dessert", 7.8, 2, 5);
		Dessert d3("Donut", "Dessert", 9.3, 1.5, 5);
		Dessert d4("Banana Split", "Dessert", 9.5, 3, 5);
		meals.push_back(s1);
		meals.push_back(s2);
		meals.push_back(s3);
		meals.push_back(m1);
		meals.push_back(m2);
		meals.push_back(m3);
		meals.push_back(m4);
		meals.push_back(f1);
		meals.push_back(f2);
		meals.push_back(f3);
		meals.push_back(f4);
		meals.push_back(d1);
		meals.push_back(d2);
		meals.push_back(d3);
		meals.push_back(d4);
		salads.push_back(s1);
		salads.push_back(s2);
		salads.push_back(s3);
		fastFoods.push_back(f1);
		fastFoods.push_back(f2);
		fastFoods.push_back(f3);
		fastFoods.push_back(f4);
		mainDishes.push_back(m1);
		mainDishes.push_back(m2);
		mainDishes.push_back(m3);
		mainDishes.push_back(m4);
		desserts.push_back(d1);
		desserts.push_back(d2);
		desserts.push_back(d3);
		desserts.push_back(d4);
	}

	void writeMealsToFile() {
		for (auto meal : meals) {
			meal.getName();
			meal.getCategory();
			meal.getRating();
			meal.getPrice();
			meal.getTax();
			meal.dataWriteToFileMeal("Meals.txt", meal.getName(), meal.getCategory(), meal.getRating(), meal.getPrice(), meal.getTax());

		}
	}

	void readMealsFromFile() {
		Meal meal;
		cout << meal.getDataFromFileMeal("Meals.txt");
	}


	void addMeal(string name, string category, double rating, double price, double tax) {
		meals.push_back(Meal(name, category, rating, price, tax));
	}
	void deleteMealByName(string name) {
		Meal meal;
		for (auto item : meals) {
			if (item.getName() == name) {
				meal = item;
				break;
			}
		}
		meals.remove(meal);
	}
	void deleteMealByID(int ID) {
		Meal meal;
		for (auto item : meals) {
			if (item.getID() == ID) {
				meal = item;
				break;
			}
		}
		meals.remove(meal);
	}
	void deleteAllMeals() {
		meals.clear();
	}
	void updateMeal(int ID, string name, string category, double rating, double price, double tax) {
		/*Meal meal;
		for (auto item : meals) {
			if (item.getID() == ID) {
				item.setName(name);
				item.setCategory(category);
				item.setRating(rating);
				item.setPrice(price);
				item.setTax(tax);
				item.showMeal();
				break;
			}
		}*/

		for_each(meals.begin(), meals.end(), [&](Meal& meal) {
			if (meal.getID() == ID)
			{
				meal.setName(name);
				meal.setCategory(category);
				meal.setRating(rating);
				meal.setPrice(price);
				meal.setTax(tax);
			}
			});
	}
	double searchMeal(string name) {
		Meal meal;
		for (auto meal : meals) {
			meal.getName() == name;
			break;
		}
		return meal.getID();
	}
	void showSearchMeal(int ID) {
		Meal meal;
		for (auto meal : meals) {
			meal.getID() == ID;
			break;
		}
		meal.showMeal();
	}

	void order(int ID) {
		Meal meal;
		for (auto item : meals) {
			if (item.getID() == ID) {
				meal = item;
				break;
			}
		}
		orders.push_back(meal);
		meal.showMeal();

	}

	double getMealsPrice() {
		double mealPrice = 0;
		for (auto item : orders) {
			mealPrice = item.getPrice() + mealPrice;
		}
		return mealPrice;
	}

	void increaseRating(int ID) {
		for_each(meals.begin(), meals.end(), [&](Meal& meal) {
			if (meal.getID() == ID)
			{
				double prevRating = meal.getRating();
				meal.setRating(prevRating + 0.3);
			}
			});
	}
	void decreaseRating(int ID) {
		for_each(meals.begin(), meals.end(), [&](Meal& meal) {
			if (meal.getID() == ID)
			{
				double prevRating = meal.getRating();
				meal.setRating(prevRating - 0.3);
			}
			});
	}

	void showSalads() {
		for (auto salad : salads) {
			salad.showMeal();
		}
	}
	void showMainDishes() {
		for (auto mainDish : mainDishes) {
			mainDish.showMeal();
		}
	}
	void showFastFoods() {
		for (auto fastFood : fastFoods) {
			fastFood.showMeal();
		}
	}
	void showDesserts() {
		for (auto dessert : desserts) {
			dessert.showMeal();
		}
	}

	void sortByName(string order) {
		meals.sort(byNameMeal(order));
	}
	void sortByNameSalad(string order) {
		salads.sort(byNameMeal(order));
	}
	void sortByNameMainDish(string order) {
		mainDishes.sort(byNameMeal(order));
	}
	void sortByNameFastFood(string order) {
		fastFoods.sort(byNameMeal(order));
	}
	void sortByNameDessert(string order) {
		desserts.sort(byNameMeal(order));
	}
	void sortByRating(string order) {
		meals.sort(byRatingMeal(order));
	}
	void sortByRatingSalad(string order) {
		salads.sort(byRatingMeal(order));
	}
	void sortByRatingMainDish(string order) {
		mainDishes.sort(byRatingMeal(order));
	}
	void sortByRatingFastFood(string order) {
		fastFoods.sort(byRatingMeal(order));
	}
	void sortByRatingDessert(string order) {
		desserts.sort(byRatingMeal(order));
	}
	void sortByPrice(string order) {
		meals.sort(byPriceMeal(order));
	}
	void sortByPriceSalad(string order) {
		salads.sort(byPriceMeal(order));
	}
	void sortByPriceMainDish(string order) {
		mainDishes.sort(byPriceMeal(order));
	}
	void sortByPriceFastFood(string order) {
		fastFoods.sort(byPriceMeal(order));
	}
	void sortByPriceDessert(string order) {
		desserts.sort(byPriceMeal(order));
	}
	void sortByTax(string order) {
		meals.sort(byTaxMeal(order));
	}
	void sortByTaxSalad(string order) {
		salads.sort(byTaxMeal(order));
	}
	void sortByTaxMainDish(string order) {
		mainDishes.sort(byTaxMeal(order));
	}
	void sortByTaxFastFood(string order) {
		fastFoods.sort(byTaxMeal(order));
	}
	void sortByTaxDessert(string order) {
		desserts.sort(byTaxMeal(order));
	}



	void show() {
		for (auto meal : meals) {
			meal.showMeal();
		}
	}


	void showByCategorySalad() {
		for (auto salad : salads) {
			salad.showMeal();
		}
	}
	void showByCategoryMainDish() {
		for (auto maindish : mainDishes) {
			maindish.showMeal();
		}
	}
	void showByCategoryFastFood() {
		for (auto fastfood : fastFoods) {
			fastfood.showMeal();
		}
	}
	void showByCategoryDessert() {
		for (auto dessert : desserts) {
			dessert.showMeal();
		}
	}

	void showOrders() {
		for (auto order : orders) {
			order.showMeal();
		}
	}

	double showIncome() {
		double income = 0;
		for (auto order : orders) {
			income = order.getPrice() + income;
		}
		return income;
	}

	void showStock() {
		stock.show();
	}

};
