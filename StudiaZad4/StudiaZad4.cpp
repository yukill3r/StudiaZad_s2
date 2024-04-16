#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

struct letter{
	char symbol;
	int count = 0;
};

auto prepare_list () {
	letter symbol;
	list <letter> lista;

	for (int x='a'; x<='z'; x++){
		symbol.symbol = char(x);
		symbol.count = 0;
		lista.push_back(symbol);
	}
	return lista;
}

string to_lower_correction (string zdanie){
	transform(zdanie.begin(), zdanie.end(), zdanie.begin(), ::tolower);
	return zdanie;
}

int main () {
	string zdanie = "The quick brown fox jumps over the lazy dog";
	auto lista = prepare_list();
	zdanie = to_lower_correction(zdanie);

	for (char x: zdanie){
		for (letter &z: lista){
			if (z.symbol == x){
				z.count++;
			}
		}
	}

	bool panagram = true;
	for (auto x: lista){
		printf("%c, %i\n", x.symbol, x.count);
		if (x.count == 0){
			panagram = false;
		}
	}

	if (panagram){
		printf("Podane zdanie jest panagramem");
	} else {
		printf("Podane zdanie nie jest panagramem");
	}
}