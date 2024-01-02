//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <string>


class triangle {
public:
	float side_a;
	float side_b;
	float side_c;

	void PrintData() {
		system("CLS");
		printf("Podaj bok a\n");
		std::cin >> side_a;
		printf("Podaj bok b\n");
		std::cin >> side_b;
		printf("Podaj bok c\n");
		std::cin >> side_c;
		float p, s;
		p = (side_a + side_b + side_c) / 2;
		s = sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
		system("CLS");
		printf("p = %f, s = %f\n", p, s);
		return;}};

class person {
public:
	char name[20];
	char surname[20];
	char city[20];
	int age;

	void PrintData() {
		system("CLS");
		printf("Podaj imie:\n");
		std::cin >> name;
		printf("Podaj nazwisko\n");
		std::cin >> surname;
		printf("Podaj miasto\n");
		std::cin >> city;
		printf("Podaj wiek\n");
		std::cin >> age;
		system("CLS");
		printf("Twoje imie to: %s\nTwoje nazwisko to: %s\nTwoje miasto %s\nTwoj wiek to: %i\n", name, surname, city, age);
		return;}};

class sort {
public:
	std::list <int> lista = {};
	int partition;
	void lowestABC(int a, int b, int c) {
		if (a < b && a < c) {
			system("CLS");
			printf("Najmniejsza liczba to a %i\n", a); }
		if (b < a && b < c) {
			system("CLS");
			printf("Najmniejsza liczba to b %i\n", b); }
		if (c < a && c < b) {
			system("CLS");
			printf("Najmniejsza liczba to c %i\n", c); } }

	void addElement(int n) { lista.push_back(n); }

	void removeLastElement() {
		lista.pop_back(); }

	void sortList()  { 
		lista.sort(); }//tbd

	void PrintData() {  for (auto number : lista) {  printf("%i ", number); }  } };

class dividers{
public:
	std::list <int> dividers_list;
	auto dividersNumber(int number){
		dividers_list.clear();
		for (int n = 1; n <= number; n++){
			if (number % n == 0){
				dividers_list.push_back(n); } };
		return &dividers_list; }

	bool primaryVerify(int number) {
		dividers_list.clear();
		int temp_s = 0;
		for (int n = 1; n <= number; n++){
			if (temp_s > 2) { return false; }
			if (number % n == 0) { temp_s++; } }
		return true; }

	bool checkPerfectNumber(int number){
		dividers_list.clear();
		int temp_s = 0;
		auto dividers_l = dividersNumber(number);
		for (auto n : *dividers_l) { temp_s += n; }

		if ((temp_s - number) == number) return true;
		else return false; } };

class sum_b {
public:
	int ten_to_hund(){
		int suma = 0;
		for (int n = 10; n <= 100; n++) { suma += n; }
		return suma; }

	int one_to_n(int liczba) {
		int suma = 0;
		for (int n = 1; n <= liczba; n++) { suma += n; }
		return suma; } };

class equations{
public:
	int x;
	int a;
	int b;
	std::string linearEquation(int a, int b){
		if (a == 0){
			if (b == 0) { return "rownanie tozsamosciowe\n"; }
			else { return "rownanie sprzeczne\n"; } }
		else{
			x = -b / a;
			return std::to_string(x); } }

	std::string determinant(int numbersArray[3][1]) {
		int W = numbersArray[0][0] * numbersArray[1][1] - numbersArray[1][0] * numbersArray[0][1];
		int WX = numbersArray[2][0] * numbersArray[1][1] - numbersArray[1][0] * numbersArray[2][1];
		int WY = numbersArray[0][0] * numbersArray[2][1] - numbersArray[2][0] * numbersArray[0][1];
		if (W == 0){
			if (WX == 0){
				if (WY == 0){
					return "Uklad rownan jest sprzeczny"; } } else { return "Uklad rownan jest nieoznaczony"; } }
		else {
			int x = WX / W;
			int y = WY / W;
			return "Rozwiazanie rownania to x: %s oraz y: %s", std::to_string(x), std::to_string(y); } } };

int main()
{
	int var = 0;
	int n = 0;
	bool exit = true;
	bool exit2 = true;
	char dump[20] = {};
	person person{};
	triangle triangle{};
	sort sort{};
	dividers dividers{};
	sum_b sum_b{};
	equations equations{};

	while (exit) {
		var = 0;
		system("CLS");
		printf("Wybierz program: \n");
		printf("\t1. Dane osobowe\n");
		printf("\t2. Pole trojkata\n");
		printf("\t3. Najmniejsza liczba\n");
		printf("\t5. Dzielniki (dodatkowe menu)\n");
		printf("\t6. Sumy wyrazen (dodatkowe menu)\n");
		printf("\t7. Rownania (dodatkowe menu)\n");
		printf("\t9. Sortuj liczby (dodatkowe menu)\n");
		printf("\t0. Exit\n");
		std::cin >> var;
		switch (var){
		case 1: {
			person.PrintData();
			system("pause");
			std::cin.clear();
			break; }
		case 2: {
			triangle.PrintData();
			system("pause");
			std::cin.clear();
			break; }
		case 3: {
			int a=0, b=0, c=0;
			system("CLS");
			printf("Podaj liczbe a\n");
			std::cin >> a;
			system("CLS");
			printf("Podaj liczbe b\n");
			std::cin >> b;
			system("CLS");
			printf("Podaj liczbe c\n");
			std::cin >> c;
			system("CLS");
			sort.lowestABC(a, b, c);
			system("pause");
			std::cin.clear();
			break; }
		case 5: {
			bool exit2 = true;
			while (exit2) {
				var = 0;
				std::cin.clear();
				system("CLS");
				printf("Wybierz program:\n");
				printf("\t1. Lista wszystkich dzielnikow podanej liczby\n");
				printf("\t2. Sprawdz czy podana liczba jest liczba pierwsza\n");
				printf("\t3. Sprawdz czy podana liczba jest liczba doskonala\n");
				printf("\t0. Exit\n");
				std::cin >> var;
				switch (var) {
				case 1: {
					n = 0;
					std::cin.clear();
					system("CLS");
					printf("Podaj liczbe ktorej chcesz uzyskac dzielniki\n");
					std::cin >> n;
					auto var = dividers.dividersNumber(n);
					system("CLS");
					printf("Dzielniki liczby %i to\n", n);
					for (auto liczba : *var) { printf("%i, ", liczba); }
					printf("\n");
					system("pause");
					std::cin.clear();
					break; }
				case 2: {
					n = 0;
					std::cin.clear();
					system("CLS");
					printf("Podaj liczbe ktora chcesz sprawdzic\n");
					std::cin >> n;
					bool tv = dividers.primaryVerify(n);
					system("CLS");
					if (tv) printf("Liczba %i jest liczba pierwsza \n", n);
					else printf("Liczba %i nie jest liczba pierwsza \n", n);
					system("pause");
					std::cin.clear();
					break; }
				case 3:{
					n = 0;
					std::cin.clear();
					system("CLS");
					printf("Podaj liczbe ktora chcesz sprawdzic\n");
					std::cin >> n;
					bool tv = dividers.checkPerfectNumber(n);
					system("CLS");
					if (tv) printf("Liczba %i jest liczba doskonala \n", n);
					else printf("Liczba %i nie jest liczba doskonala \n", n);
					std::cin.clear();
					system("pause");
					break; }
				case 0: {
					exit2 = false;
					break; } } }
			break; }
		case 6:{
			var = 0;
			exit2 = true;
			while (exit2) {
				n = 0;
				std::cin.clear();
				system("CLS");
				printf("Wybierz program:\n");
				printf("\t1. Suma od 10 do 100\n");
				printf("\t2. Suma od 1 do podanej liczby\n");
				printf("\t0. Exit\n");
				std::cin >> var;
				switch (var) {
				case 1: {
					int l = sum_b.ten_to_hund();
					system("CLS");
					printf("%i\n", l);
					system("pause");
					break; }
				case 2: {
					std::cin.clear();
					system("CLS");
					printf("Podaj liczbe\n");
					std::cin >> n;
					int l = sum_b.one_to_n(n);
					printf("Suma liczb od 1 do n dla liczby %i wynosi %i\n", n, l);
					system("pause");
					break; }
				case 0: {
					exit2 = false;
					break; } } }
			break; }
		case 7: {
			var = 0;
			exit2 = true;
			while (exit2) {
				int a = 0, b = 0;
				std::cin.clear();
				system("CLS");
				printf("Wybierz program:\n");
				printf("\t1. Rownanie liniowe\n");
				printf("\t2. Wyznaczniki\n");
				printf("\t0. Exit\n");
				std::cin >> var;
				switch (var) {
				case 1: {
					printf("Podaj a\n");
					std::cin >> a;
					printf("Podaj b\n");
					std::cin >> b;
					auto x = equations.linearEquation(a, b);
					system("CLS");
					std::cout << "Wynik rownania dla a = " << a << " oraz b = " << b << " Wynik rownania: " << x << std::endl;
					system("pause");
					break; }
				case 2: {
					int numbersArray[3][1]{};
					std::string text = "";
					system("CLS");
					for (int n = 0; n <= 2; n++) {
						for (int m = 0; m <= 1; m++) {
							printf("Podaj %c%i\n", char('A' + n), m + 1);
							std::cin >> numbersArray[n][m];
							system("CLS"); } }
					text = equations.determinant(numbersArray);
					system("CLS");
					std::cout << text << std::endl;
					system("pause");
					break; }
				case 0: {
					exit2 = false;
					break; } } }
			break; }
		case 9: {
			var = 0;
			exit2 = true;
			while (exit2) {
				n = 0;
				std::cin.clear();
				system("CLS");
				printf("Lista: ");
				for (auto liczba : sort.lista) { printf("%i, ", liczba); }
				printf("\n");
				printf("Wybierz program:\n");
				printf("\t1. Dodaj element\n");
				printf("\t2. Usun ostatni element\n");
				printf("\t3. Sortuj liste\n");
				printf("\t0. Exit\n");
				std::cin >> var;
				switch (var) {
				case 1: {
					printf("Podaj liczbe do dodania:\n");
					while (!(std::cin >> n)) {
						std::cin.clear();
						continue; }
					sort.addElement(n);
					continue; }
				case 2: {
					sort.removeLastElement();
					break; }
				case 3: {
					sort.sortList();
					break; }
				case 0: {
					exit2 = false;
					break; } } }
			break; }
		case 0:{
			return 0;
			break; } } } }