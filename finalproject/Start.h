#pragma once
#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <Windows.h>
#include <fstream>
#include "Menu.h"
#include "Ingredient.h"
#include "Meal.h"
#include "AdminClient.h"
#include "Restaurant.h"
using namespace std;

void start() {
	Admin a("Zaur", "Jafarov", 19, "+994553467069", "zaurcfr", "zaur123");
	Admin a1("Zaur", "Jafarov", 19, "+994553467069", "a", "a");
	string username;
	string password;
	Client c;
	Stock s;
	Kitchen k;
	Restaurant r("Marco's Bistro", "Saint Mark's, Portland", "Liberty City", 0);

	int ingredientID;
	string ingredientName;
	int ingredientCount;
	double ingredientFat;
	double ingredientProtein;
	double ingredientCarbohydrates;
	int ingredientKcal;
	double ingredientPrice;

	int mealID;
	string mealName;
	string mealCategory;
	double mealRating;
	double mealPrice;
	double mealTax;

	int count = 0;
	string str;

	s.writeDataToFileIngredient();
	k.writeDataToFileMeal();
	/*cout << s.getDataFromFileIngredient("Ingredient.txt");
	cout << k.getDataFromFileMeal("Meal.txt");
	Sleep(10000);*/

FirstMenu:
	k.clearOrders();
	s.clearOrderIngredients();
	system("cls");
	printMenu(r);
	char operation1;
	cin >> operation1;
	int goBack;
	switch (operation1)
	{
	ClientMenu:
	case '1':
		cin >> c;
		system("cls");
		cout << "Xosh geldiniz " << c.getName() << " bey! Menumuzda istediyiniz kategoriyani secib yemeklere baxa bilersiniz." << endl;
	ShowCategories:
		printCategories();
		int operation2;
		cin >> operation2;
		switch (operation2)
		{
		case 1:
			system("cls");
			k.showByCategorySalad();
			printClientMenu();
			int operationSalad;
			cin >> operationSalad;
			switch (operationSalad)
			{
			OrderSalad:
			case 1:
				cout << "Istediyiniz yemeyin ID'sini daxil edin: "; // ----> Sifarish vermek!!!!!!!
				cin >> mealID;
				k.order(mealID);
				char operationAddIngredientSalad;
				cout << "Yemeyinize her hansisa ingredient elave etmek isteyerdiniz ? (y/n): "; cin >> operationAddIngredientSalad;
			AddIngredientToOrderSalad:
				system("cls");
				if (operationAddIngredientSalad == 'y')
				{
					system("cls");
					s.show();
					cout << "Istediyiniz ingredientin ID'sini daxil edin: ";
					cin >> ingredientID;
					s.addIngredientToOrder(ingredientID);
					cout << endl;
					cout << "Yene elave etmek isteyerdiz ?(y/n)"; cin >> operationAddIngredientSalad;
					if (operationAddIngredientSalad == 'y') goto AddIngredientToOrderSalad;
					else if (operationAddIngredientSalad == 'n') goto AddIngredientToOrderSalad;
					else { cout << "Sechim duzgun deyil!" << endl; goto AddIngredientToOrderSalad; }
				}
				else if (operationAddIngredientSalad == 'n')
				{
				AdditionalOrderSalad:
					char operationAddMealSalad;
					cout << "Elave olaraq yene yemek sifarish etmek isterdiniz ? (y/n): "; cin >> operationAddMealSalad;
					if (operationAddMealSalad == 'y')
					{
						system("cls");
						goto ShowCategories;
					}
					else if (operationAddMealSalad == 'n') {
						system("cls");
						goto NoAdditionalOrderSalad;
					}
					else
					{
						cout << "Sechim duzgun deyil!" << endl;
						system("cls");
						k.showByCategorySalad();
						goto OrderSalad;
					}
				NoAdditionalOrderSalad:
					system("cls");
					cout << "Sifarishiniz: \n"; k.showOrders();
					cout << endl << endl;
					s.showOrderedIngredients();
					cout << "\nUmumi qiymet: " << k.getMealsPrice() + finalPrice;
					cout << "\n\nDavam etmek uchun 1-e basin" << endl;
					int goForward;
					cin >> goForward;
					if (goForward == 1)
					{
						printEatingMeal();
						cin >> goForward;
						if (goForward == 1) {
							system("cls");
							cout << "Bizi sechdiyiniz ucun teshekkur edirik!" << endl;
							k.increaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else if (goForward == 2) {
							system("cls");
							cout << "Umid edirik gelen defe beyenersiz!" << endl;
							k.decreaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else {
							system("cls");
							goto NoAdditionalOrderSalad;
						}
					}
					else {
						cout << "Sechim duzgun daxil edilmeyib" << endl;
						Sleep(1500);
						system("cls");
						goto NoAdditionalOrderSalad;
					}
				}
				else
				{
					cout << "Sechim duzgun deyil!" << endl;
					goto OrderSalad;
				}
				break;
			SortingMenuForSalad:
			case 2:
				system("cls");
				printSortedMenuForClientMeal();
				int operationSaladSort;
				cin >> operationSaladSort;
				system("cls");
				switch (operationSaladSort)
				{
				case 1:
					system("cls");
					k.sortByNameSalad("Asc");
					k.showSalads();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationSalad;
					if (operationSalad == 1)
					{
						goto OrderSalad;
						system("cls");
					}
					else if (operationSalad == 0) {
						system("cls");
						goto SortingMenuForSalad;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForSalad;
					}
					break;
				case 2:
					system("cls");
					k.sortByNameSalad("Desc");
					k.showSalads();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationSalad;
					if (operationSalad == 1)
					{
						goto OrderSalad;
						system("cls");
					}
					else if (operationSalad == 0) {
						system("cls");
						goto SortingMenuForSalad;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForSalad;
					}
					break;
				case 3:
					system("cls");
					k.sortByRatingSalad("Asc");
					k.showSalads();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationSalad;
					if (operationSalad == 1)
					{
						goto OrderSalad;
						system("cls");
					}
					else if (operationSalad == 0) {
						system("cls");
						goto SortingMenuForSalad;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForSalad;
					}
					break;
				case 4:
					system("cls");
					k.sortByRatingSalad("Desc");
					k.showSalads();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationSalad;
					if (operationSalad == 1)
					{
						goto OrderSalad;
						system("cls");
					}
					else if (operationSalad == 0) {
						system("cls");
						goto SortingMenuForSalad;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForSalad;
					}
					break;
				case 5:
					system("cls");
					k.sortByPriceSalad("Asc");
					k.showSalads();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationSalad;
					if (operationSalad == 1)
					{
						goto OrderSalad;
						system("cls");
					}
					else if (operationSalad == 0) {
						system("cls");
						goto SortingMenuForSalad;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForSalad;
					}
					break;
				case 6:
					system("cls");
					k.sortByPriceSalad("Desc");
					k.showSalads();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationSalad;
					if (operationSalad == 1)
					{
						goto OrderSalad;
						system("cls");
					}
					else if (operationSalad == 0) {
						system("cls");
						goto SortingMenuForSalad;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForSalad;
					}
					break;
				case 0:
					system("cls");
					goto ShowCategories;
					break;
				default:
					cout << "Sechimi duzgun daxil edin!" << endl;
					goto SortingMenuForSalad;
					break;
				}
			case 0:
				system("cls");
				goto ShowCategories;
				break;
			default:
				cout << "Sechim duzgun daxil edilmeyib!" << endl;
				Sleep(1500);
				system("cls");
				goto ShowCategories;
				break;
			}
			break;
		case 2:
			system("cls");
			k.showByCategoryMainDish();
			printClientMenu();
			int operationMainDish;
			cin >> operationMainDish;
			switch (operationMainDish)
			{
			OrderMainDish:
			case 1:
				cout << "Istediyiniz yemeyin ID'sini daxil edin: "; // ----> Sifarish vermek!!!!!!!
				cin >> mealID;
				k.order(mealID);
				char operationAddIngredientMainDish;
				cout << "Yemeyinize her hansisa ingredient elave etmek isteyerdiniz ? (y/n): "; cin >> operationAddIngredientMainDish;
			AddIngredientToOrderMainDish:
				system("cls");
				if (operationAddIngredientMainDish == 'y')
				{
					system("cls");
					s.show();
					cout << "Istediyiniz ingredientin ID'sini daxil edin: ";
					cin >> ingredientID;
					s.addIngredientToOrder(ingredientID);
					cout << endl;
					cout << "Yene elave etmek isteyerdiz ?(y/n)"; cin >> operationAddIngredientMainDish;
					if (operationAddIngredientMainDish == 'y') goto AddIngredientToOrderMainDish;
					else if (operationAddIngredientMainDish == 'n') goto AddIngredientToOrderMainDish;
					else { cout << "Sechim duzgun deyil!" << endl; goto AddIngredientToOrderMainDish; }
				}
				else if (operationAddIngredientMainDish == 'n')
				{
				AdditionalOrderMainDish:
					char operationAddMealMainDish;
					cout << "Elave olaraq yene yemek sifarish etmek isterdiniz ? (y/n): "; cin >> operationAddMealMainDish;
					if (operationAddMealMainDish == 'y')
					{
						system("cls");
						goto ShowCategories;
					}
					else if (operationAddMealMainDish == 'n') {
						system("cls");
						goto NoAdditionalOrderMainDish;
					}
					else
					{
						cout << "Sechim duzgun deyil!" << endl;
						system("cls");
						k.showByCategorySalad();
						goto OrderSalad;
					}
				NoAdditionalOrderMainDish:
					system("cls");
					cout << "Sifarishiniz: \n"; k.showOrders();
					cout << endl << endl;
					s.showOrderedIngredients();
					cout << "\nUmumi qiymet: " << k.getMealsPrice() + finalPrice;
					int goForward;
					cout << "\n\nDavam etmek ucun 1-e basin" << endl;
					cin >> goForward;
					if (goForward == 1) {
						printEatingMeal();
						cin >> goForward;
						if (goForward == 1) {
							system("cls");
							cout << "Bizi sechdiyiniz ucun teshekkur edirik!" << endl;
							k.increaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else if (goForward == 2) {
							system("cls");
							cout << "Umid edirik gelen defe beyenersiz!" << endl;
							k.decreaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else {
							system("cls");
							goto NoAdditionalOrderMainDish;
						}
					}
					else {
						cout << "Sechim duzgun daxil edilmeyib" << endl;
						Sleep(1500);
						system("cls");
						goto NoAdditionalOrderSalad;
					}
				}
				else
				{
					cout << "Sechim duzgun deyil!" << endl;
					goto OrderMainDish;
				}
				break;
			SortingMenuForMainDish:
			case 2:
				system("cls");
				printSortedMenuForClientMeal();
				int operationMainDishSort;
				cin >> operationMainDishSort;
				system("cls");
				switch (operationMainDishSort)
				{
				case 1:
					system("cls");
					k.sortByNameMainDish("Asc");
					k.showMainDishes();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationMainDish;
					if (operationMainDish == 1)
					{
						goto OrderMainDish;
						system("cls");
					}
					else if (operationMainDish == 0) {
						system("cls");
						goto SortingMenuForMainDish;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForMainDish;
					}
					break;
				case 2:
					system("cls");
					k.sortByNameMainDish("Desc");
					k.showMainDishes();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationMainDish;
					if (operationMainDish == 1)
					{
						goto OrderMainDish;
						system("cls");
					}
					else if (operationMainDish == 0) {
						system("cls");
						goto SortingMenuForMainDish;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForMainDish;
					}
					break;
				case 3:
					system("cls");
					k.sortByRatingMainDish("Asc");
					k.showMainDishes();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationMainDish;
					if (operationMainDish == 1)
					{
						goto OrderMainDish;
						system("cls");
					}
					else if (operationMainDish == 0) {
						system("cls");
						goto SortingMenuForMainDish;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForMainDish;
					}
					break;
				case 4:
					system("cls");
					k.sortByRatingMainDish("Desc");
					k.showMainDishes();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationMainDish;
					if (operationMainDish == 1)
					{
						goto OrderMainDish;
						system("cls");
					}
					else if (operationMainDish == 0) {
						system("cls");
						goto SortingMenuForMainDish;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForMainDish;
					}
					break;
				case 5:
					system("cls");
					k.sortByPriceMainDish("Asc");
					k.showMainDishes();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationMainDish;
					if (operationMainDish == 1)
					{
						goto OrderMainDish;
						system("cls");
					}
					else if (operationMainDish == 0) {
						system("cls");
						goto SortingMenuForMainDish;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForMainDish;
					}
					break;
				case 6:
					system("cls");
					k.sortByPriceMainDish("Desc");
					k.showMainDishes();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationMainDish;
					if (operationMainDish == 1)
					{
						goto OrderMainDish;
						system("cls");
					}
					else if (operationMainDish == 0) {
						system("cls");
						goto SortingMenuForMainDish;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForMainDish;
					}
					break;
				case 0:
					system("cls");
					goto ShowCategories;
					break;
				default:
					cout << "Sechimi duzgun daxil edin!" << endl;
					goto SortingMenuForMainDish;
					break;
				}
			case 0:
				system("cls");
				goto ShowCategories;
				break;
			default:
				cout << "Sechim duzgun daxil edilmeyib!" << endl;
				Sleep(1500);
				system("cls");
				goto ShowCategories;
				break;
			}
			break;
		case 3:
			system("cls");
			k.showByCategoryFastFood();
			printClientMenu();
			int operationFastFood;
			cin >> operationFastFood;
			switch (operationFastFood)
			{
			OrderFastFood:
			case 1:
				cout << "Istediyiniz yemeyin ID'sini daxil edin: "; // ----> Sifarish vermek!!!!!!!
				cin >> mealID;
				k.order(mealID);
				char operationAddIngredientFastFood;
				cout << "Yemeyinize her hansisa ingredient elave etmek isteyerdiniz ? (y/n): "; cin >> operationAddIngredientFastFood;
			AddIngredientToOrderFastFood:
				system("cls");
				if (operationAddIngredientFastFood == 'y')
				{
					system("cls");
					s.show();
					cout << "Istediyiniz ingredientin ID'sini daxil edin: ";
					cin >> ingredientID;
					s.addIngredientToOrder(ingredientID);
					cout << endl;
					cout << "Yene elave etmek isteyerdiz ?(y/n)"; cin >> operationAddIngredientFastFood;
					if (operationAddIngredientFastFood == 'y') goto AddIngredientToOrderFastFood;
					else if (operationAddIngredientFastFood == 'n') goto AddIngredientToOrderFastFood;
					else { cout << "Sechim duzgun deyil!" << endl; goto AddIngredientToOrderFastFood; }
				}
				else if (operationAddIngredientFastFood == 'n')
				{
				AdditionalOrderFastFood:
					char operationAddMealFastFood;
					cout << "Elave olaraq yene yemek sifarish etmek isterdiniz ? (y/n): "; cin >> operationAddMealFastFood;
					if (operationAddMealFastFood == 'y')
					{
						system("cls");
						goto ShowCategories;
					}
					else if (operationAddMealFastFood == 'n') {
						system("cls");
						goto NoAdditionalOrderFastFood;
					}
					else
					{
						cout << "Sechim duzgun deyil!" << endl;
						system("cls");
						k.showByCategorySalad();
						goto OrderSalad;
					}
				NoAdditionalOrderFastFood:
					system("cls");
					cout << "Sifarishiniz: \n"; k.showOrders();
					cout << endl << endl;
					s.showOrderedIngredients();
					cout << "\nUmumi qiymet: " << k.getMealsPrice() + finalPrice;
					int goForward;
					cout << "\n\nDavam etmek ucun 1-e basin" << endl;
					cin >> goForward;
					if (goForward == 1) {

						printEatingMeal();
						cin >> goForward;
						if (goForward == 1) {
							system("cls");
							cout << "Bizi sechdiyiniz ucun teshekkur edirik!" << endl;
							k.increaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else if (goForward == 2) {
							system("cls");
							cout << "Umid edirik gelen defe beyenersiz!" << endl;
							k.decreaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else {
							system("cls");
							goto NoAdditionalOrderFastFood;
						}
					}
					else {
						cout << "Sechim duzgun daxil edilmeyib" << endl;
						Sleep(1500);
						system("cls");
						goto NoAdditionalOrderSalad;
					}
				}
				else
				{
					cout << "Sechim duzgun deyil!" << endl;
					goto OrderFastFood;
				}
				break;
			SortingMenuForFastFood:
			case 2:
				printSortedMenuForClientMeal();
				int operationFastFoodSort;
				cin >> operationFastFoodSort;
				system("cls");
				switch (operationFastFoodSort)
				{
				case 1:
					system("cls");
					k.sortByNameFastFood("Asc");
					k.showFastFoods();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationFastFood;
					if (operationFastFood == 1)
					{
						goto OrderFastFood;
						system("cls");
					}
					else if (operationFastFood == 0) {
						system("cls");
						goto SortingMenuForFastFood;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForFastFood;
					}
					break;
				case 2:
					system("cls");
					k.sortByNameFastFood("Desc");
					k.showFastFoods();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationFastFood;
					if (operationFastFood == 1)
					{
						goto OrderFastFood;
						system("cls");
					}
					else if (operationFastFood == 0) {
						system("cls");
						goto SortingMenuForFastFood;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForFastFood;
					}
					break;
				case 3:
					system("cls");
					k.sortByRatingFastFood("Asc");
					k.showFastFoods();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationFastFood;
					if (operationFastFood == 1)
					{
						goto OrderFastFood;
						system("cls");
					}
					else if (operationFastFood == 0) {
						system("cls");
						goto SortingMenuForFastFood;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForFastFood;
					}
					break;
				case 4:
					system("cls");
					k.sortByRatingFastFood("Desc");
					k.showFastFoods();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationFastFood;
					if (operationFastFood == 1)
					{
						goto OrderFastFood;
						system("cls");
					}
					else if (operationFastFood == 0) {
						system("cls");
						goto SortingMenuForFastFood;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForFastFood;
					}
					break;
				case 5:
					system("cls");
					k.sortByPriceFastFood("Asc");
					k.showFastFoods();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationFastFood;
					if (operationFastFood == 1)
					{
						goto OrderFastFood;
						system("cls");
					}
					else if (operationFastFood == 0) {
						system("cls");
						goto SortingMenuForFastFood;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForFastFood;
					}
					break;
				case 6:
					system("cls");
					k.sortByPriceFastFood("Desc");
					k.showFastFoods();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationFastFood;
					if (operationFastFood == 1)
					{
						goto OrderFastFood;
						system("cls");
					}
					else if (operationFastFood == 0) {
						system("cls");
						goto SortingMenuForFastFood;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForFastFood;
					}
					break;
				default:
					cout << "Sechimi duzgun daxil edin!" << endl;
					goto SortingMenuForFastFood;
					break;
				}
			case 0:
				system("cls");
				goto ShowCategories;
				break;
			default:
				cout << "Sechim duzgun daxil edilmeyib!" << endl;
				Sleep(1500);
				system("cls");
				goto ShowCategories;
				break;
			}
			break;
		case 4:
			system("cls");
			k.showByCategoryDessert();
			printClientMenu();
			int operationDessert;
			cin >> operationDessert;
			switch (operationDessert)
			{
			OrderDessert:
			case 1:
				cout << "Istediyiniz yemeyin ID'sini daxil edin: "; // ----> Sifarish vermek!!!!!!!
				cin >> mealID;
				k.order(mealID);
				char operationAddIngredientDessert;
				cout << "Yemeyinize her hansisa ingredient elave etmek isteyerdiniz ? (y/n): "; cin >> operationAddIngredientDessert;
			AddIngredientToOrderDessert:
				system("cls");
				if (operationAddIngredientDessert == 'y')
				{
					system("cls");
					s.show();
					cout << "Istediyiniz ingredientin ID'sini daxil edin: ";
					cin >> ingredientID;
					s.addIngredientToOrder(ingredientID);
					cout << endl;
					cout << "Yene elave etmek isteyerdiz ?(y/n)"; cin >> operationAddIngredientDessert;
					if (operationAddIngredientDessert == 'y') goto AddIngredientToOrderDessert;
					else if (operationAddIngredientDessert == 'n') goto AddIngredientToOrderDessert;
					else { cout << "Sechim duzgun deyil!" << endl; goto AddIngredientToOrderDessert; }
				}
				else if (operationAddIngredientDessert == 'n')
				{
				AdditionalOrderDessert:
					char operationAddMealDessert;
					cout << "Elave olaraq yene yemek sifarish etmek isterdiniz ? (y/n): "; cin >> operationAddMealDessert;
					if (operationAddMealDessert == 'y')
					{
						system("cls");
						goto ShowCategories;
					}
					else if (operationAddMealDessert == 'n') {
						system("cls");
						goto NoAdditionalOrderDessert;
					}
					else
					{
						cout << "Sechim duzgun deyil!" << endl;
						system("cls");
						k.showByCategorySalad();
						goto OrderSalad;
					}
				NoAdditionalOrderDessert:
					system("cls");
					cout << "Sifarishiniz: \n"; k.showOrders();
					cout << endl << endl;
					s.showOrderedIngredients();
					cout << "\nUmumi qiymet: " << k.getMealsPrice() + finalPrice;
					int goForward;
					cout << "\n\nDavam etmek ucun 1-e basin" << endl;
					cin >> goForward;
					if (goForward == 1) {

						printEatingMeal();
						cin >> goForward;
						if (goForward == 1) {
							system("cls");
							cout << "Bizi sechdiyiniz ucun teshekkur edirik!" << endl;
							k.increaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else if (goForward == 2) {
							system("cls");
							cout << "Umid edirik gelen defe beyenersiz!" << endl;
							k.decreaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else {
							system("cls");
							goto NoAdditionalOrderDessert;
						}
					}
					else {
						cout << "Sechim duzgun daxil edilmeyib" << endl;
						Sleep(1500);
						system("cls");
						goto NoAdditionalOrderSalad;
					}
				}
				else
				{
					cout << "Sechim duzgun deyil!" << endl;
					goto OrderDessert;
				}
				break;
			SortingMenuForDessert:
			case 2:
				printSortedMenuForClientMeal();
				int operationDessertSort;
				cin >> operationDessertSort;
				system("cls");
				switch (operationDessertSort)
				{
				case 1:
					system("cls");
					k.sortByNameDessert("Asc");
					k.showDesserts();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationDessert;
					if (operationDessert == 1)
					{
						goto OrderDessert;
						system("cls");
					}
					else if (operationDessert == 0) {
						system("cls");
						goto SortingMenuForDessert;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDessert;
					}
					break;
				case 2:
					system("cls");
					k.sortByNameDessert("Desc");
					k.showDesserts();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationDessert;
					if (operationDessert == 1)
					{
						goto OrderDessert;
						system("cls");
					}
					else if (operationDessert == 0) {
						system("cls");
						goto SortingMenuForDessert;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDessert;
					}
					break;
				case 3:
					system("cls");
					k.sortByRatingDessert("Asc");
					k.showDesserts();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationDessert;
					if (operationDessert == 1)
					{
						goto OrderDessert;
						system("cls");
					}
					else if (operationDessert == 0) {
						system("cls");
						goto SortingMenuForDessert;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDessert;
					}
					break;
				case 4:
					system("cls");
					k.sortByRatingDessert("Desc");
					k.showDesserts();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationDessert;
					if (operationDessert == 1)
					{
						goto OrderDessert;
						system("cls");
					}
					else if (operationDessert == 0) {
						system("cls");
						goto SortingMenuForDessert;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDessert;
					}
					break;
				case 5:
					system("cls");
					k.sortByPriceDessert("Asc");
					k.showDesserts();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationDessert;
					if (operationDessert == 1)
					{
						goto OrderDessert;
						system("cls");
					}
					else if (operationDessert == 0) {
						system("cls");
						goto SortingMenuForDessert;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDessert;
					}
					break;
				case 6:
					system("cls");
					k.sortByPriceDessert("Desc");
					k.showDesserts();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationDessert;
					if (operationDessert == 1)
					{
						goto OrderDessert;
						system("cls");
					}
					else if (operationDessert == 0) {
						system("cls");
						goto SortingMenuForDessert;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDessert;
					}
					break;
				case 0:
					system("cls");
					goto ShowCategories;
					break;
				default:
					cout << "Sechimi duzgun daxil edin!" << endl;
					goto SortingMenuForDessert;
					break;
				}
			case 0:
				system("cls");
				goto ShowCategories;
				break;
			default:
				cout << "Sechim duzgun daxil edilmeyib!" << endl;
				Sleep(1500);
				system("cls");
				goto ShowCategories;
				break;
			}
			break;
		CategoryAllDishes:
		case 5:
			system("cls");
			k.show();
			printClientMenu();
			int operationAllDishes;
			cin >> operationAllDishes;
			switch (operationAllDishes)
			{
			OrderDish:
			case 1:
				cout << "Istediyiniz yemeyin ID'sini daxil edin: "; // ----> Sifarish vermek!!!!!!!
				cin >> mealID;
				k.order(mealID);
				char operationAddIngredientDish;
				cout << "Yemeyinize her hansisa ingredient elave etmek isteyerdiniz ? (y/n): "; cin >> operationAddIngredientDish;
			AddIngredientToOrderDish:
				system("cls");
				if (operationAddIngredientDish == 'y')
				{
					system("cls");
					s.show();
					cout << "Istediyiniz ingredientin ID'sini daxil edin: ";
					cin >> ingredientID;
					s.addIngredientToOrder(ingredientID);
					cout << endl;
					cout << "Yene elave etmek isteyerdiz ?(y/n)"; cin >> operationAddIngredientDish;
					if (operationAddIngredientDish == 'y') goto AddIngredientToOrderDish;
					else if (operationAddIngredientDish == 'n') goto AddIngredientToOrderDish;
					else { cout << "Sechim duzgun deyil!" << endl; goto AddIngredientToOrderDish; }
				}
				else if (operationAddIngredientDish == 'n')
				{
				AdditionalOrderDish:
					char operationAddMealDish;
					cout << "Elave olaraq yene yemek sifarish etmek isterdiniz ? (y/n): "; cin >> operationAddMealDish;
					if (operationAddMealDish == 'y')
					{
						system("cls");
						goto ShowCategories;
					}
					else if (operationAddMealDish == 'n') {
						system("cls");
						goto NoAdditionalOrderDish;
					}
					else
					{
						cout << "Sechim duzgun deyil!" << endl;
						system("cls");
						k.showByCategorySalad();
						goto OrderSalad;
					}
				NoAdditionalOrderDish:
					system("cls");
					cout << "Sifarishiniz: \n"; k.showOrders();
					cout << endl << endl;
					s.showOrderedIngredients();
					cout << "\nUmumi qiymet: " << k.getMealsPrice() + finalPrice;
					int goForward;
					cout << "\n\nDavam etmek ucun 1-e basin" << endl;
					cin >> goForward;
					if (goForward == 1) {

						printEatingMeal();
						cin >> goForward;
						if (goForward == 1) {
							system("cls");
							cout << "Bizi sechdiyiniz ucun teshekkur edirik!" << endl;
							k.increaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else if (goForward == 2) {
							system("cls");
							cout << "Umid edirik gelen defe beyenersiz!" << endl;
							k.decreaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else {
							system("cls");
							goto NoAdditionalOrderDish;
						}
					}
					else {
						cout << "Sechim duzgun daxil edilmeyib" << endl;
						Sleep(1500);
						system("cls");
						goto NoAdditionalOrderSalad;
					}
				}
				else
				{
					cout << "Sechim duzgun deyil!" << endl;
					goto OrderDish;
				}
				break;
			SortingMenuForDish:
			case 2:
				printSortedMenuForClientMeal();
				int operationDishSort;
				cin >> operationDishSort;
				system("cls");
				switch (operationDishSort)
				{
				case 1:
					system("cls");
					k.sortByName("Asc");
					k.show();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationAllDishes;
					if (operationAllDishes == 1)
					{
						goto OrderDish;
						system("cls");
					}
					else if (operationAllDishes == 0) {
						system("cls");
						goto SortingMenuForDish;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDish;
					}
					break;
				case 2:
					system("cls");
					k.sortByName("Desc");
					k.show();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationAllDishes;
					if (operationAllDishes == 1)
					{
						goto OrderDish;
						system("cls");
					}
					else if (operationAllDishes == 0) {
						system("cls");
						goto SortingMenuForDish;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDish;
					}
					break;
				case 3:
					system("cls");
					k.sortByRating("Asc");
					k.show();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationAllDishes;
					if (operationAllDishes == 1)
					{
						goto OrderDish;
						system("cls");
					}
					else if (operationAllDishes == 0) {
						system("cls");
						goto SortingMenuForDish;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDish;
					}
					break;
				case 4:
					system("cls");
					k.sortByRating("Desc");
					k.show();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationAllDishes;
					if (operationAllDishes == 1)
					{
						goto OrderDish;
						system("cls");
					}
					else if (operationAllDishes == 0) {
						system("cls");
						goto SortingMenuForDish;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDish;
					}
					break;
				case 5:
					system("cls");
					k.sortByPrice("Asc");
					k.show();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationAllDishes;
					if (operationAllDishes == 1)
					{
						goto OrderDish;
						system("cls");
					}
					else if (operationAllDishes == 0) {
						system("cls");
						goto SortingMenuForDish;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDish;
					}
					break;
				case 6:
					system("cls");
					k.sortByPrice("Desc");
					k.show();
					cout << "\nSifarish vermek ucun 1\nGeriye donmek ucun 0-a basin." << endl;
					cin >> operationAllDishes;
					if (operationAllDishes == 1)
					{
						goto OrderDish;
						system("cls");
					}
					else if (operationAllDishes == 0) {
						system("cls");
						goto SortingMenuForDish;
					}
					else {
						cout << "Sechim yanlishdir!" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDish;
					}
					break;
				case 0:
					system("cls");
					goto ShowCategories;
					break;
				default:
					cout << "Sechimi duzgun daxil edin!" << endl;
					goto SortingMenuForDish;
					break;
				}
			case 0:
				system("cls");
				goto ShowCategories;
				break;
			default:
				cout << "Sechim yanlishdir!" << endl;
				Sleep(1500);
				system("cls");
				goto ShowCategories;
				break;
			}
			break;
		case 0:
			system("cls");
			goto FirstMenu;
			break;
		default:
			cout << "Secim duzgun daxil edilmeyib!" << endl;
			Sleep(1500);
			system("cls");
			goto ShowCategories;
			break;
		}
		break;
	AdminMenu:
	case '2':
		system("cls");
		cout << "Zehmet olmasa username ve password'u daxil edin!" << endl;
		cout << "Melumatlarinizi 3 defe sehv yazsaz, ilk menuya yonlendirileceksiniz" << endl;
		cout << "username: "; cin >> username;
		cout << "password: "; cin >> password;
		if (a1.signIN(username, password) != 0) {
			cout << "Xosh geldiniz " << a1.getName() << " bey! Siz buradan Stock'a ve Kitchen'a baxa bilersiniz." << endl;
		AdminSignInMenu:
			printAdminMenu();
			int operationAdmin;
			cin >> operationAdmin;
			switch (operationAdmin)
			{
			StockMenu:
			case 1:
				system("cls");
				printStockMenu();
				int operationStock;
				cin >> operationStock;
				switch (operationStock)
				{
				StockShow:
				case 1:
					s.show();
					cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
					if (goBack == 0) {
						goto StockMenu;
					}
					else {
						cout << "Sechim yanlishdir" << endl;
						goto StockShow;
					}
					break;
				case 2:
					system("cls");
					getline(cin, str);
					cout << "Ingredientin adini daxil edin: "; getline(cin, ingredientName);
					cout << "Ingredientin sayini daxil edin: "; cin >> ingredientCount;
					cout << "Ingredientin yaglilig faizini daxil edin: "; cin >> ingredientFat;
					cout << "Ingredientin protein miqdarini daxil edin: "; cin >> ingredientProtein;
					cout << "Ingredientin carbohydrat deyerini daxil edin: "; cin >> ingredientCarbohydrates;
					cout << "Ingredientin kCal deyerini daxil edin: "; cin >> ingredientKcal;
					cout << "Ingredientin qiymetini daxil edin: "; cin >> ingredientPrice;
					s.addIngredient(ingredientName, ingredientCount, ingredientFat, ingredientProtein, ingredientCarbohydrates, ingredientKcal, ingredientPrice);
					cout << "Ingredient Stocka elave olundu. Baxmaq ucun: (y/n)";
					char operationStockAdd;
					cin >> operationStockAdd;
					if (operationStockAdd == 'y') {
						s.show();
						Sleep(5000);
						goto StockMenu;
					}
					else if (operationStockAdd == 'n') {
						goto StockMenu;
					}
					else
					{
						cout << "Sechim duzgun daxil edilmeyib." << endl;
						Sleep(500);
						goto StockMenu;
					}
					break;
				case 3:
					system("cls");
					printStockDeleteMenu();
					int operationStockDelete;
					cin >> operationStockDelete;
					if (operationStockDelete == 1) {
						s.show();
						cout << "Ingredientin ID'sini daxil edin: "; cin >> ingredientID;
						s.deleteIngredientByID(ingredientID);
						system("cls");
						cout << "\nIngredient stockdan silindi\n" << endl;
						s.show();
						Sleep(5000);
						goto StockMenu;
					}
					else if (operationStockDelete == 2) {
						s.show();
						getline(cin, str);
						cout << "Ingredientin adini daxil edin:"; getline(cin, ingredientName);
						s.deleteIngredientByName(ingredientName);
						system("cls");
						cout << "\nIngredient stockdan silindi\n" << endl;
						s.show();
						Sleep(5000);
						goto StockMenu;
					}
					else if (operationStockDelete == 3) {
						system("cls");
						s.deleteAllIngredient();
						cout << "Butun stock temizlendi.\nSilinmeden sonra stock:" << endl;
						s.show();
					}
					else if (operationStockDelete == 0) {
						goto StockMenu;
					}
					else
					{
						cout << "Sechimi duzgun daxil edin!" << endl;
						Sleep(1000);
						goto StockMenu;
					}
					break;
				SortedMenuForIngredient:
				case 4:
					printSortedMenuForIngredient();
					int operationStockSortedMenu;
					cin >> operationStockSortedMenu;
					switch (operationStockSortedMenu)
					{
					case 1:
						s.sortByName("Asc");
						s.show();
						cout << "Geri donmek ucun 0-a basin" << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 2:
						s.sortByName("Desc");
						s.show();
						cout << "Geri donmek ucun 0-a basin" << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 3:
						printAscOrDesc();
						cin >> operationStockSortedMenu;
						if (operationStockSortedMenu == 1) s.sortByCount("Asc");
						else if (operationStockSortedMenu == 2)	s.sortByCount("Desc");
						else cout << "Sechimi duzgun daxil edin!" << endl;
						s.show();
						cout << "Geri donmek ucun 0-a basin" << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 4:
						printAscOrDesc();
						cin >> operationStockSortedMenu;
						if (operationStockSortedMenu == 1) s.sortByFat("Asc");
						else if (operationStockSortedMenu == 2)	s.sortByFat("Desc");
						else cout << "Sechimi duzgun daxil edin!" << endl;
						s.show();
						cout << "Geri donmek ucun 0-a basin" << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 5:
						printAscOrDesc();
						cin >> operationStockSortedMenu;
						if (operationStockSortedMenu == 1) s.sortByProtein("Asc");
						else if (operationStockSortedMenu == 2)	s.sortByProtein("Desc");
						else cout << "Sechimi duzgun daxil edin!" << endl;
						s.show();
						cout << "Geri donmek ucun 0-a basin" << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 6:
						printAscOrDesc();
						cin >> operationStockSortedMenu;
						if (operationStockSortedMenu == 1) s.sortByCarbohydrates("Asc");
						else if (operationStockSortedMenu == 2)	s.sortByCarbohydrates("Desc");
						else cout << "Sechimi duzgun daxil edin!" << endl;
						s.show();
						cout << "Geri donmek ucun 0-a basin" << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 7:
						printAscOrDesc();
						cin >> operationStockSortedMenu;
						if (operationStockSortedMenu == 1) s.sortByKcal("Asc");
						else if (operationStockSortedMenu == 2)	s.sortByKcal("Desc");
						else cout << "Sechimi duzgun daxil edin!" << endl;
						s.show();
						cout << "Geri donmek ucun 0-a basin" << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 8:
						printAscOrDesc();
						cin >> operationStockSortedMenu;
						if (operationStockSortedMenu == 1) s.sortByPrice("Asc");
						else if (operationStockSortedMenu == 2)	s.sortByPrice("Desc");
						else cout << "Sechimi duzgun daxil edin!" << endl;
						s.show();
						cout << "Geri donmek ucun 0-a basin" << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 0:
						goto StockMenu;
						break;
					default:
						break;
					}
					break;
				IncreaseCountOfIngredient:
				case 5:
					system("cls");
					s.show();
					cout << "Miqdarini artirmaq istediyiniz ingredientin ID'sini daxil edin: ";
					cin >> ingredientID;
					cout << "Miqdari daxil edin: ";
					cin >> ingredientCount;
					s.increaseCount(ingredientID, ingredientCount);
					s.show();
					cout << "Elave artirmaq isteyirsinizse 1\nGeriye donmek isteyirsinizse 0-a basin" << endl;
					int operationIncreaseIngredient;
					cin >> operationIncreaseIngredient;
					if (operationIncreaseIngredient == 1)
					{
						system("cls");
						goto IncreaseCountOfIngredient;
					}
					else if (operationIncreaseIngredient == 0) {
						system("cls");
						goto StockMenu;
					}
					else {
						cout << "Sechiminizi duzgun daxil edin!" << endl;
						goto StockMenu;
					}
					break;
				case 0:
					system("cls");
					goto FirstMenu;
					break;
				default:
					break;
				}
				break;
			KitchenMenu:
			case 2:
				system("cls");
				printKitchenMenu();
				int operationKitchen;
				cin >> operationKitchen;
				switch (operationKitchen)
				{
				Kitchen1:
				case 1:
					//Sifarishlere baxmag
					system("cls");
					cout << "Gunluk sifarishler: \n"; k.showOrdersForAdmin();
					cout << endl << endl;
					s.showOrderedIngredientsForAdmin();
					r.setBudget(k.showIncome() + s.showIngredientIncome());
					cout << "\nGunluk gelir: $" << r.getBudget() << endl;
					cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
					if (goBack == 0) {
						goto KitchenMenu;
					}
					else {
						cout << "Sechim yanlishdir" << endl;
						goto KitchenShow;
					}
					break;
				KitchenShow:
				case 2:
					//Yemeklere baxmaq
					k.show();
					cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
					if (goBack == 0) {
						goto KitchenMenu;
					}
					else {
						cout << "Sechim yanlishdir" << endl;
						goto KitchenShow;
					}
					break;
				Kitchen4:
				case 3:
					//Yemek elave etmek
					system("cls");
					getline(cin, str);
					cout << "Yemeyin adini daxil edin: "; getline(cin, mealName);
					cout << "Yemeyin kateqoriyasini daxil edin: "; getline(cin, mealCategory);
					cout << "Yemeyin ratingini daxil edin: "; cin >> mealRating;
					cout << "Yemeyin qiymetini daxil edin: "; cin >> mealPrice;
					cout << "Yemeyin vergisini daxil edin: "; cin >> mealTax;
					k.addMeal(mealName, mealCategory, mealRating, mealPrice, mealTax);
					cout << "Yemek metbexe elave olundu. Baxmaq ucun: (y/n)";
					char operationMealAdd;
					cin >> operationMealAdd;
					if (operationMealAdd == 'y') {
						k.show();
						Sleep(5000);
						goto KitchenMenu;
					}
					else if (operationMealAdd == 'n') {
						goto KitchenMenu;
					}
					else
					{
						cout << "Sechim duzgun daxil edilmeyib." << endl;
						Sleep(500);
						goto KitchenMenu;
					}
					break;
				Kitchen5:
				case 4:
					//Yemek silmek
					system("cls");
					printKitchenDeleteMenu();
					int operationKitchenDelete;
					cin >> operationKitchenDelete;
					k.show();
					if (operationKitchenDelete == 1) {
						cout << "Yemeyin ID'sini daxil edin: "; cin >> mealID;
						k.deleteMealByID(mealID);
						system("cls");
						cout << "\nYemek silindi\n" << endl;
						k.show();
						cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
						if (goBack == 0) {
							goto KitchenMenu;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto KitchenMenu;
						}
					}
					else if (operationKitchenDelete == 2) {
						cout << "Yemeyin adini daxil edin:"; cin >> mealName;
						k.deleteMealByName(mealName);
						system("cls");
						cout << "\nYemek silindi\n" << endl;
						k.show();
						cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
						if (goBack == 0) {
							goto KitchenMenu;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto KitchenMenu;
						}
					}
					else if (operationKitchenDelete == 3) {
						system("cls");
						k.deleteAllMeals();
						cout << "Butun yemekler silindi.\nSilinmeden sonra metbex:" << endl;
						k.show();
						cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
						if (goBack == 0) {
							goto KitchenMenu;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto KitchenMenu;
						}
					}
					else if (operationKitchenDelete == 0) {
						goto KitchenMenu;
					}
					else
					{
						cout << "Sechimi duzgun daxil edin!" << endl;
						Sleep(1000);
						goto KitchenMenu;
					}
					break;
				Kitchen6:
				case 5:
					//Yemeklere duzelish etmek
					k.show();
					cout << "Duzelish etmek istediyiniz yemeyin ID'sini daxil edin: "; cin >> mealID;
					getline(cin, str);
					cout << "Duzelish etmek istediyiniz yemeyin adini daxil edin: "; getline(cin, mealName);
					cout << "Duzelish etmek istediyiniz yemeyin kateqoriyasini daxil edin: "; getline(cin, mealCategory);
					cout << "Duzelish etmek istediyiniz yemeyin ratingini daxil edin: "; cin >> mealRating;
					cout << "Duzelish etmek istediyiniz yemeyin qiymetini daxil edin: "; cin >> mealPrice;
					cout << "Duzelish etmek istediyiniz yemeyin vergisini daxil edin: "; cin >> mealTax;
					k.updateMeal(mealID, mealName, mealCategory, mealRating, mealPrice, mealTax);
					k.show();
					cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
					if (goBack == 0) {
						goto KitchenMenu;
					}
					else {
						cout << "Sechim yanlishdir" << endl;
						goto KitchenMenu;
					}
					break;
				Kitchen7:
				case 6:
					//Stocka baxmaq
					s.show();
					cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
					if (goBack == 0) {
						system("cls");
						goto AdminSignInMenu;
					}
					else {
						cout << "Sechim yanlishdir" << endl;
						goto KitchenShow;
					}
					break;
				SortedMenuForMeal:
				case 7:
					//Yemeklerin sortlashdirilmis siyahisi
					system("cls");
					printSortedMenuForMeal();
					int operationStockMealMenu;
					cin >> operationStockMealMenu;
					switch (operationStockMealMenu)
					{
					case 1:
						k.sortByName("Asc");
						k.show();
						cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
						if (goBack == 0) {
							goto SortedMenuForMeal;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto SortedMenuForMeal;
						}
						break;
					case 2:
						k.sortByName("Desc");
						k.show();
						cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
						if (goBack == 0) {
							goto SortedMenuForMeal;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto SortedMenuForMeal;
						}
						break;
					case 3:
						printAscOrDesc();
						cin >> operationStockMealMenu;
						if (operationStockMealMenu == 1) k.sortByRating("Asc");
						else if (operationStockMealMenu == 2)	k.sortByRating("Desc");
						else cout << "Sechimi duzgun daxil edin!" << endl;
						k.show();
						cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
						if (goBack == 0) {
							goto SortedMenuForMeal;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto SortedMenuForMeal;
						}
						break;
					case 4:
						printAscOrDesc();
						cin >> operationStockMealMenu;
						if (operationStockMealMenu == 1) k.sortByPrice("Asc");
						else if (operationStockMealMenu == 2)	k.sortByPrice("Desc");
						else cout << "Sechimi duzgun daxil edin!" << endl;
						k.show();
						cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
						if (goBack == 0) {
							goto SortedMenuForMeal;
						}
						else {
							cout << "Sechim yanlishdir" << endl;
							goto SortedMenuForMeal;
						}
						break;
					case 0:
						goto KitchenMenu;
						break;
					default:
						break;
					}
					break;
				case 8:
					cout << "==================Nottifications==================" << endl;
					cout << "Masa nomre: " << c.getTableNo() << endl;
					cout << "Sifarishler: " << endl;
					k.nottForOrdersMeal();
					s.nottForOrdersIngredient();
					cout << "Geri donmek ucun 0-a basin"; cin >> goBack;
					if (goBack == 0) {
						system("cls");
						goto AdminSignInMenu;
					}
					else {
						cout << "Sechim yanlishdir" << endl;
						goto KitchenShow;
					}
					break;
				case 0:
					//Geri donmek
					system("cls");
					goto FirstMenu;
					break;
				default:
					break;
				}
				break;
			case 0:
				system("cls");
				goto FirstMenu;
				break;
			default:
				cout << "Sechim yanlishdir!" << endl;
				Sleep(1000);
				system("cls");
				goto AdminSignInMenu;
				break;
			}
		}
		else
		{
			count++;
			if (count < 3)
			{
				cout << 3 - count << " shansiniz qaldi." << endl;
				Sleep(1000);
				goto AdminMenu;
			}
			else {
				system("cls");
				goto FirstMenu;
			}
		}
		break;
	default:
		cout << "Secim duzgun daxil edilmeyib!" << endl;
		Sleep(1500);
		system("cls");
		goto FirstMenu;
		break;
	}
}
