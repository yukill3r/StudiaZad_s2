#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
#include <stdio.h>


class fileManipulation {
private:
    std::ifstream openedFile;
    std::list <int> readedFile;
public:

    auto returnList() {
        return this->readedFile;
    }

    void openFile(std::string file_location) {
        this->openedFile.open(file_location);
    }

    void closeFile() {
        if (this->openedFile.is_open()){
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
                std::getline (this->openedFile, myline);
                this->readedFile.push_back(std::stof(myline));
            }
        }
    }

    void writeFile(string file, string line){
        eFile.open (file);
        eFile << line + "\n";
        eFile.close();
    }
};

class Programs{
public:
    const float pi = atan(1) * 4;

    auto circle_area(float r) {
        return (pi * pow(r,2));
    }
};




int main() {
    fileManipulation fileManipulation;
    Programs Programs;
    
    bool exit = false;
    int var = 0;
    std::string file;

    while (!(exit)){
        std::system("CLS");
        printf("Wybierz program: \n");
        printf("\t1. 10 liczb + wypisz na ekranie\n");

        std::cin >> var;
        switch (var) {
            case 1: {
                file = "promienie.txt";
                std::list <float> area;
                fileManipulation.openFile(file);
                fileManipulation.readFile();
                for (auto i: fileManipulation.returnList()) {
                    area.push_back(Programs.circle_area(i));
                }
                area.sort();
                fileManipulation.closeFile();

                string temp;
                for (auto i: area) {
                    temp = std::to_string(i);
                    fileManipulation.writeFile("wynik.txt", temp);
                }
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
    Ćwiczenie 1. Napisz program, który pobierze z pliku promienie.txt 
promienie dwóch kół. Twoim zadaniem jest stworzenie tego pliku ręcznie 
(z poziomu systemu operacyjnego), następnie otwarcie tego pliku za pomocą 
C++ oraz wyznaczenie pól kół i zapianie wyników posortowanych rosnąco 
(najpierw mniejsze pole, następnie większe) do pliku wynik.txt.

    Ćwiczenie 2. Napisz program, który pobierze z pliku dane.txt trzy liczby 
całkowite (plik dane.txt tworzymy ręcznie z poziomu systemu operacyjnego) wyliczy 
pole trapezu i wynik zapisze w pliku pole.txt. 

    Ćwiczenie 3.  Stwórz plik dane.txt z poziomu systemu operacyjnego i wpisz 
do niego 5 liczb całkowitych. Otwórz ten plik z poziomu C++, pobierz wszystkie 
liczby i do pliku wynik.txt zapisz tylko te, których cyfra jedności kończy się 
na 0, 3, 8 lub 9.

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