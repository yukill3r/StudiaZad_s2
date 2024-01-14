#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
#include <stdio.h>
#include <string>
#include <iterator>
#include <algorithm>

template< template<typename, typename> class Container, typename Separator >
Container<std::string, std::allocator<std::string> > split(const std::string& line, Separator sep) {
    std::size_t pos = 0;
    std::size_t next = 0;

    Container<std::string, std::allocator<std::string> > fields;
    while (next != std::string::npos) {
        next = line.find_first_of(sep, pos);
        std::string field = next == std::string::npos ? line.substr(pos) : line.substr(pos, next - pos);
        fields.push_back(field);
        pos = next + 1;
    }
    return fields;
}

class fileManipulation {
private:
    std::ifstream openedFile;
    std::list <std::string> readedFile;

public:
    auto returnList() {
        return this->readedFile;
    }

    void openFile(std::string file_location) {
        this->openedFile.open(file_location);
    }

    void closeFile() {
        if (this->openedFile.is_open()) {
            this->openedFile.close();
        }
    }

    void readFile() {
        std::string myline;

        if (this->openedFile.is_open()) {
            while (this->openedFile) {
                if (this->openedFile.eof()) {
                    break;
                }
                std::getline(this->openedFile, myline);
                this->readedFile.push_back(myline);
            }
        }
    }

    void clearList() {
        this->readedFile.clear();
    }

    void writeFile(std::string file, std::string line) {
        std::ofstream extractFile;
        extractFile.open(file);
        extractFile << (line + "\n");
        extractFile.close();
    }

    void popFirstArgument() {
        this->readedFile.pop_front();
    }
};

class Programs{
public:
    const float pi = atan(1) * 4;

    auto circle_area(float r) {
        return (pi * pow(r,2));
    }

    auto trapezoid_area(float a, float b, float h) {
        return (((a + b) / 2) * h);
    }

    std::string converToOneString(std::list <float>& area) {
        std::string one_liner;
        for (auto i : area) {
            one_liner += std::to_string(i);
            one_liner += "\n";
        }
        return one_liner;
    }
};

int main() {
    fileManipulation fileManipulation;
    Programs Programs;
    
    bool exit = false;
    int var = 0;

    std::string file{};
    std::list <float> area{};

    while (!(exit)){
        std::system("CLS");
        printf("Wybierz program: \n");
        printf("\t1. Pola okregu bazowane na pliku promienie.txt\n");
        printf("\t2. Pola trapezu bazowane na pliku dane.txt\n");
        printf("\t3. Wypisane bazowane na ostatniej liczbie z pliku dane.txt\n");

        printf("\t99. Exit\n");

        std::cin >> var;
        switch (var) {
            case 1: {
                /*Format pliku promienie txt jedna liczba na linie*/
                file = "promienie.txt";

                fileManipulation.openFile(file);
                fileManipulation.readFile();
                for (auto i: fileManipulation.returnList()) {
                    area.push_back(Programs.circle_area(std::stof(i)));
                }
                area.sort();
                
                fileManipulation.writeFile("wynik.txt", Programs.converToOneString(area));
                area.clear();
                fileManipulation.clearList();
                fileManipulation.closeFile();
                break;
            }
            case 2: {
                /*Format pliku a,b,h jedna linia jeden trapez*/
                file = "dane.txt";
                fileManipulation.openFile(file);
                fileManipulation.readFile();

                for (auto i : fileManipulation.returnList()) {
                    float array[3] = {};
                    int a_i = 0;
                    auto splitted = split<std::list>(i, ',');

                    for (auto z : splitted) {
                        array[a_i] = std::stof(z);
                        a_i++;
                    }
                    area.push_back(Programs.trapezoid_area(array[0], array[1], array[2]));
                }

                fileManipulation.writeFile("wynik.txt", Programs.converToOneString(area));
                area.clear();
                fileManipulation.clearList();
                fileManipulation.closeFile();
                break;
            }
            case 3: {
                /*Pierwsza liczba pokazujaca ile bedzie loopow kolejne liczby do sprawdzenia kazda w osobnej linii*/
                int var_check[] = { 0, 3, 8, 9 };
                file = "dane.txt";
                fileManipulation.openFile(file);
                fileManipulation.readFile();
                fileManipulation.popFirstArgument();
                int last_number = 0;
                auto local_copy_of_list = fileManipulation.returnList();

                for (auto i : local_copy_of_list) {
                    last_number = std::stof(i);
                    last_number = last_number % 10;

                    bool exists = std::find(std::begin(var_check), std::end(var_check), last_number) != std::end(var_check);
                    if (exists) {
                        area.push_back(std::stof(i));
                    }
                }
                fileManipulation.writeFile("wynik.txt", Programs.converToOneString(area));
                area.clear();
                fileManipulation.clearList();
                fileManipulation.closeFile();
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

/*
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
*/


/*
    Ćwiczenie 4. W pliku dane.txt znajduje się ciąg liczb zgodny ze specyfikacją 
wejścia. Napisz program, który wyznaczy sumę cyfr każdej z liczb i zapisze 
do pliku wynik.txt.
Wejście
W pierwszej linii jedna liczba naturalna dodatnia t określająca ilość zestawów danych.
Dla każdego zestawu jedna liczba należąca do przedziału [0..1015].
Wyjście
Dla każdego zestawu jedna liczba będąca sumą cyfr danej liczby.
Przykład
Wejście:
3
5
17
345

Wyjście:
5
8
12

    Ćwiczenie 5. Napisz program, który wczyta dane z tego pliku, w którym znajdują się liczby całkowite i zapisze je do pliku wynik.txt odwrotnej kolejności.
Wejście
W pierwszym wierszu pliku znajduje się jedna liczba naturalna dodatnia n < 10000 określająca ilość liczb do wczytania.
W następnych n wierszach liczby naturalne.
Wyjście
Ciąg liczb wczytanych z pliku, zapisany w odwrotnej kolejności do pliku wynik.txt.
Przykład
Wejście:
5
1
2
3
4
54
Wyjście:
54
4
3
2
1
*/