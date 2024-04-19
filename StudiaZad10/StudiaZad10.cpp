#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <sstream>


int main () {
    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_special_character = false;
    bool longer_than_eight = false;

    std::string password;
    std::getline(std::cin, password);
    if (password.size() >= 8){
        longer_than_eight = !longer_than_eight;
    }
    if (longer_than_eight){
        for (char c:password){
            if (isupper(c) && has_upper == false){
                has_upper = !has_upper;
            }
            if (islower(c) && has_lower == false){
                has_lower = !has_lower;
            }
            if (isdigit(c) && has_digit == false){
                has_digit = !has_digit;
            }
            if (isalpha(c) && has_special_character){
                has_special_character = !has_special_character;
            }
        }
    }
    printf("Longer than 8: %i\n"
            "Has upper: %i\n"
            "Has lower: %i\n"
            "Has digit: %i\n"
            "Has special character: %i\n", longer_than_eight, has_upper, has_lower, has_digit);
    return 0;
}

