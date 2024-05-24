#include <iostream>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>

using namespace std;

class Fraction{
    public:
        Fraction(int numerator, int denominator);
        string toString();
        double toDouble();
    private:
        int numerator;
        int denominator;
};

Fraction::Fraction(int numerator, int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
}

string Fraction::toString() {
    string custom_return;
    custom_return = to_string(this->numerator) + "/" + to_string(this->denominator);
    return custom_return;
}

double Fraction::toDouble() {
    double value = 0.0;
    value = double(this->numerator) / double(this->denominator);
    return value;
}

int main(void) {
    int num, den;
    std::string input = "";
    std::vector<std::string> splitted_string_vec;
    std::cout << "s" << endl;
    std::getline(std::cin, input);

    boost::split(splitted_string_vec, input, boost::is_any_of("/"));

    num = stoi(splitted_string_vec[0]);
    den = stoi(splitted_string_vec[1]);

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
    return 0;
}

