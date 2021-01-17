#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;


class Ingredient {
	int myID;
	string name;
	int count;
	double fat;
	double protein;
	double carbohydrates;
	int kcal;
	double price;
public:
	static int ID;
	Ingredient() :name(""), fat(0), protein(0), carbohydrates(0), kcal(0), price(0) {}
	Ingredient(const string& name, const int& count, const double& fat, const double& protein, const double& carbohydrates, const int& kcal, const double& price)
	{
		setID();
		setName(name);
		setCount(count);
		setFat(fat);
		setProtein(protein);
		setCarbohydrates(carbohydrates);
		setKcal(kcal);
		setPrice(price);
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
	int getCount()const {
		return count;
	}
	void setCount(const int& count) {
		if (count > 0) this->count = count;
	}
	double getFat()const {
		return fat;
	}
	void setFat(const double& fat) {
		if (fat > 0)this->fat = fat;
	}
	double getProtein()const {
		return protein;
	}
	void setProtein(const double& protein) {
		if (protein > 0) this->protein = protein;
	}
	double getCarbohydrates()const {
		return carbohydrates;
	}
	void setCarbohydrates(const double& carbohydrates) {
		if (carbohydrates > 0) this->carbohydrates = carbohydrates;
	}
	int getKcal()const {
		return kcal;
	}
	void setKcal(const int& kcal) {
		if (kcal > 0) this->kcal = kcal;
	}
	double getPrice()const {
		return price;
	}
	void setPrice(const double& price) {
		if (price > 0) this->price = price;
	}

	bool operator==(const Ingredient& ing)const {
		return ing.getName() == getName();
	}

	/*void dataWriteToFileIngredient(string filename, string name, int count, double fat, double protein, double carbohydrates, int kcal, double price) {
		ofstream fout(filename, ios_base::app);
		if (fout.is_open())
		{
			fout << "Name: " << name << endl;
			fout << "Count: " << count << endl;
			fout << "Fat: " << fat << endl;
			fout << "Protein: " << protein << endl;
			fout << "Carbohydrates: " << carbohydrates << endl;
			fout << "Kcal: " << kcal << endl;
			fout << "Price: " << price << endl;
			fout << "========================================================" << endl;
		}
		fout << "========================================================" << endl;
		fout.close();
	}*/

	/*string getDataFromFileIngredient(const string& filename) {
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
	}*/

	virtual void show() {
		cout << "=====================================" << endl;
		cout << "ID: " << this->myID << endl;
		cout << "Name: " << getName() << endl;
		cout << "Count: " << getCount() << endl;
		cout << "Fat: " << getFat() << endl;
		cout << "Protein: " << getProtein() << endl;
		cout << "Carbohydrates: " << getCarbohydrates() << endl;
		cout << "Kcal: " << getKcal() << endl;
		cout << "Price: " << getPrice() << endl;
	}

	void showIngredientForClient() {
		cout << "=====================================" << endl;
		cout << "Name: " << getName() << endl;
		cout << "Price: " << getPrice() << endl;
	}

	virtual ~Ingredient() {}

};

int Ingredient::ID = 0;

class Mushroom :public Ingredient {
	double iron;
public:
	Mushroom() = delete;
	Mushroom(const string& name, const int& count, const double& fat, const double& protein, const double& carbohydrates, const int& kcal, const double& price, const double& iron) :Ingredient(name, count, fat, protein, carbohydrates, kcal, price) {
		setIron(iron);
	}
	double getIron()const {
		return iron;
	}
	void setIron(const double& iron) {
		if (iron >= 0) this->iron = iron;
	}

	void show()override {
		Ingredient::show();
		cout << "Iron: " << getIron() << endl;
	}
};
class Meat :public Ingredient {
	double calcium;
public:
	Meat() = delete;
	Meat(const string& name, const int& count, const double& fat, const double& protein, const double& carbohydrates, const int& kcal, const double& price, const double& calcium) :Ingredient(name, count, fat, protein, carbohydrates, kcal, price) {
		setCalcium(calcium);
	}
	double getCalcium()const {
		return calcium;
	}
	void setCalcium(const double& calcium) {
		if (calcium >= 0) this->calcium = calcium;
	}

	void show()override {
		Ingredient::show();
		cout << "Calcium: " << getCalcium() << endl;
	}
};
class Chicken :public Ingredient {
	double magnesium;
public:
	Chicken() = delete;
	Chicken(const string& name, const int& count, const double& fat, const double& protein, const double& carbohydrates, const int& kcal, const double& price, const double& magnesium) :Ingredient(name, count, fat, protein, carbohydrates, kcal, price) {
		setMagnesium(magnesium);
	}
	double getMagnesium()const {
		return magnesium;
	}
	void setMagnesium(const double& magnesium) {
		if (magnesium >= 0) this->magnesium = magnesium;
	}

	void show()override {
		Ingredient::show();
		cout << "Magnesium: " << getMagnesium() << endl;
	}
};
class Spices :public Ingredient {
	bool isSpicy;
public:
	Spices() = delete;
	Spices(const string& name, const int& count, const double& fat, const double& protein, const double& carbohydrates, const int& kcal, const double& price, const bool& isSpicy) :Ingredient(name, count, fat, protein, carbohydrates, kcal, price)
	{
		setIsSpicy(isSpicy);
	}
	double getIsSpicy()const {
		return isSpicy;
	}
	void setIsSpicy(const double& cholesterol) {
		if (cholesterol >= 0) this->isSpicy = isSpicy;
	}
	void show()override {
		Ingredient::show();
		cout << "is spicy: " << getIsSpicy() << endl;
	}
};
class Cheese :public Ingredient {
	double cholesterol;
public:
	Cheese() = delete;
	Cheese(const string& name, const int& count, const double& fat, const double& protein, const double& carbohydrates, const int& kcal, const double& price, const double& cholesterol) :Ingredient(name, count, fat, protein, carbohydrates, kcal, price)
	{
		setCholesterol(cholesterol);
	}
	double getCholesterol()const {
		return cholesterol;
	}
	void setCholesterol(const double& cholesterol) {
		if (cholesterol >= 0) this->cholesterol = cholesterol;
	}
	void show()override {
		Ingredient::show();
		cout << "Cholesterol: " << getCholesterol() << endl;
	}

};
class Tomato :public Ingredient {
	double water;
public:
	Tomato() = delete;
	Tomato(const string& name, const int& count, const double& fat, const double& protein, const double& carbohydrates, const int& kcal, const double& price, const double& water) :Ingredient(name, count, fat, protein, carbohydrates, kcal, price)
	{
		setWater(water);
	}
	double getWater()const {
		return water;
	}
	void setWater(const double& water) {
		if (water >= 0) this->water = water;
	}
	void show()override {
		Ingredient::show();
		cout << "Water: %" << getWater() << endl;
	}

};
class Potato :public Ingredient {
	double starch;
public:
	Potato() = delete;
	Potato(const string& name, const int& count, const double& fat, const double& protein, const double& carbohydrates, const int& kcal, const double& price, const double& starch) :Ingredient(name, count, fat, protein, carbohydrates, kcal, price)
	{
		setStarch(starch);
	}
	double getStarch()const {
		return starch;
	}
	void setStarch(const double& starch) {
		if (starch >= 0) this->starch = starch;
	}
	void show()override {
		Ingredient::show();
		cout << "Starch: " << getStarch() << endl;
	}

};

class byName {
	string order;
public:
	byName(string order) :order(order) {}

	bool operator()(const Ingredient& a, const Ingredient& b) {
		if (order == "Asc") return a.getName() < b.getName();
		else if (order == "Desc") return a.getName() > b.getName();
	}
};
class byCount {
	string order;
public:
	byCount(string order) :order(order) {}

	bool operator()(const Ingredient& a, const Ingredient& b) {
		if (order == "Asc") return a.getCount() < b.getCount();
		else if (order == "Desc") return a.getCount() > b.getCount();
	}
};
class byFat {
	string order;
public:
	byFat(string order) :order(order) {}

	bool operator()(const Ingredient& a, const Ingredient& b) {
		if (order == "Asc") return a.getFat() < b.getFat();
		else if (order == "Desc") return a.getFat() > b.getFat();
	}
};
class byProtein {
	string order;
public:
	byProtein(string order) :order(order) {}

	bool operator()(const Ingredient& a, const Ingredient& b) {
		if (order == "Asc") return a.getProtein() < b.getProtein();
		else if (order == "Desc") return a.getProtein() > b.getProtein();
	}
};
class byCarbohydrates {
	string order;
public:
	byCarbohydrates(string order) :order(order) {}

	bool operator()(const Ingredient& a, const Ingredient& b) {
		if (order == "Asc") return a.getCarbohydrates() < b.getCarbohydrates();
		else if (order == "Desc") return a.getCarbohydrates() > b.getCarbohydrates();
	}
};
class byKcal {
	string order;
public:
	byKcal(string order) :order(order) {}

	bool operator()(const Ingredient& a, const Ingredient& b) {
		if (order == "Asc") return a.getKcal() < b.getKcal();
		else if (order == "Desc") return a.getKcal() > b.getKcal();
	}
};
class byPrice {
	string order;
public:
	byPrice(string order) :order(order) {}

	bool operator()(const Ingredient& a, const Ingredient& b) {
		if (order == "Asc") return a.getPrice() < b.getPrice();
		else if (order == "Desc") return a.getPrice() > b.getPrice();
	}
};

double finalPrice = 0;



class Stock {
	list<Ingredient> ingredients;
	list<Ingredient> orderIngredient;
	list<Ingredient> orderIngredientListForAdmin;
public:
	Stock() {
		Mushroom mushroom("Mushroom", 100, 10, 50.2, 45, 32, 1.5, 1);
		Meat meat("Meat", 20, 42, 50, 13, 194, 3, 5);
		Chicken chicken("Chicken", 50, 32, 45, 18, 150, 2, 4);
		Spices spice("Spice", 150, 23, 15, 53, 14, 0.5, 6);
		Cheese cheese("Cheese", 70, 35, 27, 65, 28, 0.75, 1);
		Tomato tomato("Tomato", 120, 22, 40, 43, 54, 0.5, 2);
		Potato potato("Potato", 80, 15, 20, 30, 25, 0.8, 3);
		ingredients.push_back(mushroom);
		ingredients.push_back(meat);
		ingredients.push_back(chicken);
		ingredients.push_back(spice);
		ingredients.push_back(cheese);
		ingredients.push_back(tomato);
		ingredients.push_back(potato);
	}

	void writeDataToFileIngredient() {
		ofstream fout("Ingredient.txt", ios_base::out);
		if (fout.is_open())
		{
			for (auto ingredient : ingredients) {
				fout << "Name: " << ingredient.getName() << endl;
				fout << "Count: " << ingredient.getCount() << endl;
				fout << "Fat: " << ingredient.getFat() << endl;
				fout << "Protein: " << ingredient.getProtein() << endl;
				fout << "Carbohydrates: " << ingredient.getCarbohydrates() << endl;
				fout << "Kcal: " << ingredient.getKcal() << endl;
				fout << "Price: " << ingredient.getPrice() << endl;
				fout << "========================================================" << endl;
			}
		}
		fout << "========================================================" << endl;
		fout.close();
	}
	string getDataFromFileIngredient(const string& filename) {
		ifstream fin(filename, ios_base::in);
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
			cout << "Error" << endl;
		}
		return result;
	}

	void increaseCount(int ID, int count) {
		for_each(ingredients.begin(), ingredients.end(), [&](Ingredient& ingredient) {
			if (ingredient.getID() == ID)
			{
				int finalCount = ingredient.getCount() + count;
				ingredient.setCount(finalCount);
			}
			});
	}
	void decreaseCount(int ID) {
		for_each(ingredients.begin(), ingredients.end(), [&](Ingredient& ingredient) {
			if (ingredient.getID() == ID)
			{
				int prevCount = ingredient.getCount();
				ingredient.setCount(prevCount - 1);
			}
			});
	}

	void addIngredient(string name, int count, double fat, double protein, double carbohydrates, int kcal, double price) {
		ingredients.push_back(Ingredient(name, count, fat, protein, carbohydrates, kcal, price));
		writeDataToFileIngredient();
	}
	void deleteIngredientByID(int ID) {
		Ingredient ingredient;
		for (auto item : ingredients) {
			if (item.getID() == ID) {
				ingredient = item;
				break;
			}
			else
			{
				cout << "ID'ni duzgun daxil edin!" << endl;
			}
		}
		ingredients.remove(ingredient);
		writeDataToFileIngredient();
	}
	void deleteIngredientByName(string name) {
		Ingredient ingredient;
		for (auto item : ingredients) {
			if (item.getName() == name) {
				ingredient = item;
				break;
			}
			else
			{
				cout << "Adi duzgun daxil edin!" << endl;
			}
		}
		ingredients.remove(ingredient);
		writeDataToFileIngredient();
	}
	void deleteAllIngredient() {
		ingredients.clear();
		writeDataToFileIngredient();
	}

	void addIngredientToOrder(int ID) {
		Ingredient ingredient;
		for (auto item : ingredients) {
			if (item.getID() == ID) {
				ingredient = item;
				break;
			}
		}
		orderIngredient.push_back(ingredient);
		orderIngredientListForAdmin.push_back(ingredient);
		cout << ingredient.getName() << endl;
		finalPrice += ingredient.getPrice();
		cout << "Ingredientlerin umumi qiymeti: " << finalPrice;
		decreaseCount(ID);
	}
	void clearOrderIngredients() {
		orderIngredient.clear();
	}
	void showOrderedIngredients() {
		cout << "============Ingredientler============" << endl;
		for (auto ingOrder : orderIngredient) {
			ingOrder.showIngredientForClient();
		}

	}
	void showOrderedIngredientsForAdmin() {
		cout << "============Ingredientler============" << endl;
		for (auto ingOrder : orderIngredientListForAdmin) {
			ingOrder.show();
		}
	}
	double showIngredientIncome() {
		double ingredientIncome = 0;
		for (auto ingOrder : orderIngredientListForAdmin) {
			ingredientIncome = ingOrder.getPrice() + ingredientIncome;
		}
		return ingredientIncome;
	}

	void sortByName(string order) {
		ingredients.sort(byName(order));
	}
	void sortByCount(string order) {
		ingredients.sort(byCount(order));
	}
	void sortByFat(string order) {
		ingredients.sort(byFat(order));
	}
	void sortByProtein(string order) {
		ingredients.sort(byProtein(order));
	}
	void sortByCarbohydrates(string order) {
		ingredients.sort(byCarbohydrates(order));
	}
	void sortByKcal(string order) {
		ingredients.sort(byKcal(order));
	}
	void sortByPrice(string order) {
		ingredients.sort(byPrice(order));
	}

	void show() {
		for (auto ing : ingredients) {
			ing.show();
			cout << endl;
		}
	}

	void nottForOrdersIngredient() {
		for (auto order : orderIngredientListForAdmin) {
			order.show();
		}
	}

};