#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <sstream>


int main () {
    std::string word_1;
    std::string word_2;

    std::getline(std::cin, word_1);
    std::getline(std::cin, word_2);

    std::transform(word_1.begin(),word_1.end(),word_1.begin(), ::tolower);
    std::transform(word_2.begin(),word_2.end(),word_2.begin(), ::tolower);

    std::sort(word_1.begin(), word_1.end());
    std::sort(word_2.begin(), word_2.end());

    if (word_1 == word_2){
        std::cout << "anagrams" << std::endl;
    } else {
        std::cout << "not anagrams" << std::endl;
    }
}
