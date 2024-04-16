#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <sstream>

using namespace std;

int main () {
	string split_part = "";
	int list_s[4] = {0,0,0,0};
	string address = "255.255.255.255";
	bool correct = true;
	bool count = true;
	int index = 0;

	for (char x:address){
		if (!(x=='.')){
			split_part = split_part + x;
		} else {
			try
			{
				if (split_part.length()>3 || split_part.length()<0){
					throw split_part;
				}
				list_s[index] = stoi(split_part);
			}
			catch(string e)
			{
				list_s[index] = -1;
				correct = false;
			}
			index++;
			split_part = "";
		}
	}
	list_s[index] = stoi(split_part);


	for (auto x: list_s){
		if (!(x>=0 && x<=255)) {
			count = false;
		}
	}

	if (correct){
		if (count){
			std::cout << "Adress ip is correct" << endl;
		} else {
			std::cout << "Adress number not in correct number range" << endl;
		}
		} else {
		std::cout << "Adress ip is incorrect" << endl; 
		}

}