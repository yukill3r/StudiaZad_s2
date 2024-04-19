#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <sstream>

void split_string(std::string stop_words, std::list <std::string> &stop_word_list){
    std::string temp;
    for (auto x:stop_words){
        if (!(x == ',')){
            temp.push_back(x);
        } else {
            stop_word_list.push_back(temp);
            temp.clear();
        }
    }
    stop_word_list.push_back(temp);
}

void string_remove_words(std::list <std::string> stop_word_list, std::string &sentence){
    for (auto stop_word:stop_word_list){
        while (sentence.find(stop_word) != std::string::npos)
        sentence.replace(sentence.find(stop_word), stop_word.size(), "");
    }
}

int main () {
    std::list <std::string> stop_words_list;
    std::string stop_words = "has,no,this";
    std::string sentence = "This sentence has no stop words";
    //std::getline(std::cin, stop_words);
    //std::getline(std::cin, sentence);

    split_string(stop_words, stop_words_list);
    string_remove_words(stop_words_list, sentence);

    // remove stop_words from sentence here
    std::cout << sentence << "\n";
}
