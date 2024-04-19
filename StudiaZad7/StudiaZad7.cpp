#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <sstream>

using namespace std;

string word_to_replace_func(string word_to_replace, string replace_with, string sentence){
    while (sentence.find(word_to_replace) != string::npos)
        sentence.replace(sentence.find(word_to_replace), word_to_replace.size(), replace_with);
    return sentence;
}

int main()
{
    string word_to_replace;
    string replace_with;
    string sentence;
    
    printf("Co chcesz zmienic\n");
    std::getline(std::cin, word_to_replace);
    printf("na co chcesz zmienic\n");
    std::getline(std::cin, replace_with);
    printf("Zdanie w ktorym chcesz mienic\n");
    std::getline(std::cin, sentence);
    
    sentence = word_to_replace_func(word_to_replace, replace_with, sentence);

    std::cout << sentence << "\n";
}