#pragma once
#include <iostream>
using namespace std;



void printSortedMenuForMeal() {
	cout << "1. A-Z sortlashdirma" << endl;
	cout << "2. Z-A sortlashdirma" << endl;
	cout << "3. Ratinge gore sortlashdirma" << endl;
	cout << "4. Qiymete gore sortlashdirma" << endl;
	cout << "0. Geri donmek" << endl;

}

void printSortedMenuForClientMeal() {
	cout << "1. A-Z sortlashdirma" << endl;
	cout << "2. Z-A sortlashdirma" << endl;
	cout << "3. Ratinge gore sortlashdirma(artan)" << endl;
	cout << "4. Ratinge gore sortlashdirma(azalan)" << endl;
	cout << "5. Qiymete gore sortlashdirma(artan)" << endl;
	cout << "6. Qiymete gore sortlashdirma(azalan)" << endl;
	cout << "0. Geri donmek" << endl;

}
void printSortedMenuForIngredient() {
	cout << "1. A-Z sortlashdirma" << endl;
	cout << "2. Z-A sortlashdirma" << endl;
	cout << "3. Sayina gore sortlashdirma" << endl;
	cout << "4. Yaglilig derecesine gore sortlashdirma" << endl;
	cout << "5. Protein deyerine gore sortlashdirma" << endl;
	cout << "6. Karbohidrat deyerine gore sortlashdirma" << endl;
	cout << "7. Kcal deyerine gore sortlashdirma" << endl;
	cout << "8. Qiymetine gore sortlashdirma" << endl;
	cout << "0. Geri donmek" << endl;

}

void printCategories() {
	cout << "1. Salads" << endl;
	cout << "2. Main Dishes" << endl;
	cout << "3. Fast Food" << endl;
	cout << "4. Desserts" << endl;
	cout << "5. All dishes" << endl;
	cout << "0. Geri donmek" << endl;
}

void printAscOrDesc() {
	cout << "1. Artan" << endl;
	cout << "2. Azalan" << endl;
}

void printAdminMenu() {
	cout << "1. Stock" << endl;
	cout << "2. Kitchen" << endl;
	cout << "0. Geri donmek" << endl;
}

void printClientMenu() {
	cout << "\nSifarish vermek ucun 1" << endl;
	cout << "Sortlashdirilmish menuya baxmag ucun 2" << endl;
	cout << "Geriye donmek ucun 0 - a basin." << endl;
}

void printStockMenu() {
	cout << "Bura restoranin stockudur.\nAsagidaki emeliyyatlari yerine yetire bilersiz." << endl;
	cout << "1. Ingredientlere baxmaq" << endl;
	cout << "2. Ingredient elave etmek" << endl;
	cout << "3. Ingredient silmek" << endl;
	cout << "4. Ingredientlerin sortlashdirilmish siyahisi" << endl;
	cout << "5. Ingredientlerin sayini artirmaq" << endl;
	cout << "0. Geri donmek" << endl;
}
void printStockDeleteMenu() {
	cout << "1. ID'ye gore silinme" << endl;
	cout << "2. Ada gore silinme" << endl;
	cout << "3. Butun stocku silmek" << endl;
	cout << "0. Geri donmek" << endl;
}

void printKitchenMenu() {
	cout << "Bura restoranin metbexidir.\nAsagidaki emeliyyatlari yerine yetire bilersiz." << endl;
	cout << "1. Sifarishlere baxmag" << endl;
	cout << "2. Yemeklere baxmaq" << endl;
	cout << "3. Yemek elave etmek" << endl;
	cout << "4. Yemek silmek" << endl;
	cout << "5. Yemeklere duzelish etmek" << endl;
	cout << "6. Stocka baxmaq" << endl;
	cout << "7. Yemeklerin sortlashdirilmish siyahisi" << endl;
	cout << "0. Geri donmek" << endl;
}
void printKitchenDeleteMenu() {
	cout << "1. ID'ye gore silinme" << endl;
	cout << "2. Ada gore silinme" << endl;
	cout << "3. Butun yemekleri silmek" << endl;
	cout << "0. Geri donmek" << endl;
}


void printEatingMeal() {
	for (size_t i = 10; i > 0; i--)
	{
		system("cls");
		cout << "Yemek yeyilir... " << i << " seconds remaining" << endl;
		Sleep(1000);
	}
	cout << "Nush olsun." << endl;
	cout << "Yemeyi beyendiniz ?" << endl;
	cout << "1. He" << endl;
	cout << "2. Yox" << endl;
}