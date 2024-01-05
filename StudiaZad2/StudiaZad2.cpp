//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>

class SortFloat {
public:
	float* array = NULL;
	int array_size = 0;

	void ArrayGen(int length) {
		float* array{ new float[length] {} };

		for (int x = 0; x < length; x++) {
			array[x] = 0;
		}

		this->array = array;
		this->array_size = length;
		delete[] array;
	}
	void ClearList() {
		this->array = NULL;
		this->array_size = 0;
	}
	void InputData() {
		for (int x = 0; x < this->array_size; x++) {
			printf("Podaj liczbe %i/%i\n", x + 1, this->array_size);
			std::cin >> this->array[x];
			system("CLS");
			std::cin.clear();
		}
	}
};

class SortInt {
public:
	int* array = NULL;
	int array_size = 0;

	void ArrayGen(int length) {
		int* array{ new int[length] {} };

		for (int x = 0; x < length; x++) {
			array[x] = 0;
		}

		this->array = array;
		this->array_size = length;

		delete[] array;
	}
	void ClearList() {
		this->array = NULL;
		this->array_size = 0;
	}
	void InputData() {
		for (int x = 0; x < this->array_size; x++) {
			printf("Podaj liczbe %i/%i\n", x + 1, this->array_size);
			std::cin >> this->array[x];
			system("CLS");
			std::cin.clear();
		}
	}
	int FindHighest() {
		int highest = this->array[0];
		for (int x = 1; x < this->array_size; x++) {
			if (this->array[x] > highest) {
				highest = this->array[x];
			}
		}
		return highest;
	}
	int FindLowest() {
		int lowest = this->array[0];
		for (int x = 1; x < this->array_size; x++) {
			if (this->array[x] < lowest) {
				lowest = this->array[x];
			}
		}
		return lowest;
	}
	int NumberRepeats(int number) {
		int repeats = 0;
		for (int x = 0; x < this->array_size; x++) {
			if (this->array[x] == number) {
				repeats++;
			}
		}
		return repeats;
	}
	int SecondHighest() {
		int highest = this->FindHighest();
		int second_h = 0;
		for (int x = 0; x <= this->array_size; x++) {
			if (this->array[x] < highest && this->array[x] > second_h) {
				second_h = this->array[x];
			}
		}
		return second_h;
	}
	int SecondLowest() {
		int lowest = this->FindLowest();
		int second_l = this->FindHighest();
		for (int x = 0; x <= this->array_size; x++) {
			if (this->array[x] > lowest && this->array[x] < second_l) {
				second_l = this->array[x];
			}
		}
		return second_l;
	}

};


void sort_int_setup(SortInt& sort_int, int length = NULL) {
	if (length == NULL) {
		system("CLS");
		printf("Podaj maksymalna wielkosc\n");
		std::cin >> length;
		system("CLS");
	}
	system("CLS");
	sort_int.ArrayGen(length);
	sort_int.InputData();
	system("CLS");
}

void sort_float_setup(SortFloat& sort_float, int length = NULL) {
	if (length == NULL) {
		system("CLS");
		printf("Podaj maksymalna wielkosc\n");
		std::cin >> length;
		system("CLS");
	}
	system("CLS");
	sort_float.ArrayGen(length);
	sort_float.InputData();
	system("CLS");
}

int main()
{
	SortInt sort_int{};
	SortFloat sort_float{};

	int var = 0;
	int length = 0;
	bool exit = true;

	while (exit)
	{
		system("CLS");
		printf("Wybierz program: \n");
		printf("\t1. 10 liczb + wypisz na ekranie\n");
		printf("\t2. 10 liczb + odwrotnie wypisz na ekranie\n");
		printf("\t3. 30 liczb jezeli z poprawnego przedzialu\n");
		printf("\t4. Najwieksza z podanego przedzialu z powtorzeniami (zad 4 oraz 6)\n");
		printf("\t5. Najmniejsza z podanego przedzialu z powtorzeniami (zad 5 oraz 7)\n");
		printf("\t6. Druga najwyzsza z iloscia powtorzen (zad 8 oraz 10)\n");
		printf("\t7. Druga najnizsza z iloscia powtorzen (zad 9 oraz 11)\n");
		printf("\t12. Rzeczywiste do kwadratu\n");
		printf("\t13. Rzeczywiste do szescianu\n");
		printf("\t14. Rzeczywiste dodac jeden\n");
		printf("\t15. Rzeczywiste pomnozone przez dwa\n");
		printf("\t16. Parzyste z calkowitych\n");
		printf("\t17. Nieparzyste z calkowitych\n");
		printf("\t18. Podzielne przez trzy z calkowitych\n");
		printf("\t19. Liczby rzeczywiste z przedzialu [4-15)\n");
		printf("\t20. Liczby calkowite kazda segment podzielny przez dwa\n");
		printf("\t21. Liczby calkowite suma cyfr wynosi 1\n");
		printf("\t22. Liczby calkowite parzyste + 100\n");
		printf("\t23. Liczby rzeczywiste mniejsze od 0 zamiana na 0\n");
		printf("\t24. Liczby rzeczywiste pokaz tylko parzyste indeksy\n");
		printf("\t25. Liczby rzeczywiste indeksy do kwadratu\n");
		printf("\t26. sita Eratostanesa (const liczba zmiana w kodzie)\n");
		printf("\t99. Exit\n");

		std::cin >> var;
		switch (var) {
		case 1: {
			sort_int_setup(sort_int, 10);
			for (int x = 0; x < sort_int.array_size; x++) { printf("%i, ", sort_int.array[x]); }
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 2: {
			sort_int_setup(sort_int, 10);
			for (int number = sort_int.array_size - 1; number >= 0; number--) { printf("%i, ", sort_int.array[number]); }
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 3: {
			system("CLS");
			length = 0;
			printf("Podaj max znakow\n");
			std::cin >> length;
			if (length > 30) {
				system("CLS");
				printf("Liczba pzekracza maksimum elementow w tablicy\n");
			}
			else {
				sort_int.ArrayGen(length);
				sort_int.InputData();
				system("CLS");
				for (int x = 0; x < sort_int.array_size; x++) { printf("%i, ", sort_int.array[x]); }
			}
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 4: {
			sort_int_setup(sort_int);
			int highest = sort_int.FindHighest();
			int repeats = sort_int.NumberRepeats(highest);
			printf("Najwieksza z podanego przedzialu to: %i powtarzajce sie %i\n", highest, repeats);
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 5: {
			sort_int_setup(sort_int);
			int lowest = sort_int.FindLowest();
			int repeats = sort_int.NumberRepeats(lowest);
			printf("Najwieksza z podanego przedzialu to: %i powtarzajace sie: %i\n", lowest, repeats);
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 6: {
			sort_int_setup(sort_int);
			int s_highest = sort_int.SecondHighest();
			int repeats = sort_int.NumberRepeats(s_highest);
			printf("Druga najwyzsza z podanego przedzialu to: %i z iloscia powtorzen to: %i\n", s_highest, repeats);
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 7: {
			sort_int_setup(sort_int);
			int s_highest = sort_int.SecondLowest();
			int repeats = sort_int.NumberRepeats(s_highest);
			printf("Druga najnizsza z podanego przedzialu to: %i z iloscia powtorzen to: %i\n", s_highest, repeats);
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 12: {
			sort_float_setup(sort_float);
			for (int x = 0; x < sort_float.array_size; x++) { printf("Original value: %f, Power: %f\n", sort_float.array[x], pow(sort_float.array[x], 2)); }
			system("pause");
			std::cin.clear();
			sort_float.ClearList();
			break;
		}
		case 13: {
			sort_float_setup(sort_float);
			for (int x = 0; x < sort_float.array_size; x++) { printf("Original value: %f, Power: %f\n", sort_float.array[x], pow(sort_float.array[x], 3)); }
			system("pause");
			std::cin.clear();
			sort_float.ClearList();
			break;
		}
		case 14: {
			sort_float_setup(sort_float);
			for (int x = 0; x < sort_float.array_size; x++) { printf("Original value: %f, Power: %f\n", sort_float.array[x], sort_float.array[x] + 1); }
			system("pause");
			std::cin.clear();
			sort_float.ClearList();
			break;
		}
		case 15: {
			sort_float_setup(sort_float);
			for (int x = 0; x < sort_float.array_size; x++) { printf("Original value: %f, Power: %f\n", sort_float.array[x], sort_float.array[x] * 2); }
			system("pause");
			std::cin.clear();
			sort_float.ClearList();
			break;
		}
		case 16: {
			sort_int_setup(sort_int);
			for (int number = 0; number < sort_int.array_size; number++) { if (sort_int.array[number] % 2 == 0) { std::cout << sort_int.array[number] << ", "; } }
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 17: {
			sort_int_setup(sort_int);
			for (int number = 0; number < sort_int.array_size; number++) { if (!(sort_int.array[number] % 2 == 0)) { std::cout << sort_int.array[number] << ", "; } }
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 18: {
			sort_int_setup(sort_int);
			for (int number = 0; number < sort_int.array_size; number++) { if (sort_int.array[number] % 3 == 0) { std::cout << sort_int.array[number] << ", "; } }
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 19: {
			sort_float_setup(sort_float);
			for (int number = 0; number < sort_float.array_size; number++) { if (sort_float.array[number] >= 4 && sort_float.array[number] < 15) { std::cout << sort_float.array[number] << ", "; } }
			system("pause");
			std::cin.clear();
			sort_float.ClearList();
			break;
		}
		case 20: {
			sort_int_setup(sort_int);
			for (int number = 0; number < sort_int.array_size; number++) {
				std::list<int> lista{};
				int temp_number = sort_int.array[number];
				int digit = 0;
				while (temp_number > 0) {
					digit = temp_number % 10;
					if (digit % 2 == 0) {
						lista.push_front(digit);
					}
					temp_number /= 10;
				}
				temp_number = 0;
				for (auto number : lista) {
					temp_number *= 10;
					temp_number += number;
				}
				if (temp_number == sort_int.array[number]) {
					std::cout << sort_int.array[number] << ", ";
				}
			}
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 21: {
			sort_int_setup(sort_int);
			for (int number = 0; number < sort_int.array_size; number++) {
				std::list<int> lista{};
				int temp_number = sort_int.array[number];
				int digit = 0;
				while (temp_number > 0) {
					lista.push_front(temp_number % 10);
					temp_number /= 10;
				}
				temp_number = 0;
				for (auto number : lista) {
					temp_number += number;
				}
				if (temp_number == 1) {
					std::cout << sort_int.array[number] << ", ";
				}
			}
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 22: {
			sort_int_setup(sort_int);
			for (int number = 0; number < sort_int.array_size; number++) {
				if (sort_int.array[number] % 2 == 0) {
					sort_int.array[number] = sort_int.array[number] + 100;
				}
				std::cout << sort_int.array[number] << ", ";
			}
			system("pause");
			std::cin.clear();
			sort_int.ClearList();
			break;
		}
		case 23: {
			sort_float_setup(sort_float);
			for (int number = 0; number < sort_float.array_size; number++) {
				if (sort_float.array[number] < 0) {
					sort_float.array[number] = 0;
				}
				std::cout << sort_float.array[number] << ", ";
			}
			system("pause");
			std::cin.clear();
			sort_float.ClearList();
			break;
		}
		case 24: {
			sort_float_setup(sort_float);
			for (int number = 0; number < sort_float.array_size; number++) {
				if (number % 2 == 0) {
					std::cout << sort_float.array[number] << ", ";
				}
			}
			system("pause");
			std::cin.clear();
			sort_float.ClearList();
			break;
		}
		case 25: {
			sort_float_setup(sort_float);
			int x_p = 0;
			for (int x = 0; std::pow(x, 2) < sort_float.array_size; x++) {
				x_p = std::pow(x, 2);
				std::cout << sort_float.array[x_p] << ", ";
			}
			system("pause");
			std::cin.clear();
			sort_float.ClearList();
			break;
		}
		case 26: {
			const int n = 30;
			bool T[n + 1];
			unsigned i, w, g;

			for (i = 2; i <= n; i++) {
				T[i] = true;
			}
			g = sqrt(n);

			for (i = 2; i <= g; i++) {
				if (T[i]) for (w = i * i; w <= n; w += i) {
					T[w] = false;
				}
			}
			system("CLS");
			for (i = 2; i <= n; i++) {
				if (T[i]) {
					std::cout << i << " ";
				}
			}
			system("pause");
			std::cin.clear();
			break;
		}
		case 99: {
			exit = false;
			break;
		}
		}
	}
	return 0;
}
