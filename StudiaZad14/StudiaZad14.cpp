#include <iostream>
#include <string>
#include <sstream>
#include <numeric>
#include <boost/algorithm/string.hpp>

using namespace std;

class Fraction{
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
    // the functions below do not change the object
    // on which they are called, they produce a new object
    Fraction plus(Fraction that);
    Fraction minus(Fraction that);
    Fraction times(Fraction that);
    Fraction by(Fraction that);
    int gcd(Fraction that);
private:
    int numerator;
    int denominator;
    void reduce();
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

Fraction generate_fraction(int number) {
    int nominator = 0;
    int denominator = 0;
    string temp_string;
    std::vector<std::string> splitted_string_vec;
    std::cout << "Get " << number << " fraction" << endl;
    std::getline(std::cin, temp_string);
    boost::split(splitted_string_vec, temp_string, boost::is_any_of("/"));
    nominator = stoi(splitted_string_vec[0]);
    denominator = stoi(splitted_string_vec[1]);
    Fraction fraction(nominator, denominator);
    return fraction;
}

int Fraction::gcd(Fraction that){
    int gcd = std::gcd(this->denominator, that.denominator);
    return gcd;
}

Fraction Fraction::plus(Fraction that){
    int gcd = this->gcd(that);
    int numerator1_n = that.denominator / gcd * this->numerator;
    int numerator2_n = this->denominator / gcd * that.numerator;
    int numerator = numerator1_n + numerator2_n;
    Fraction result(numerator, gcd);
    return result;
}

Fraction Fraction::minus(Fraction that){
    int gcd = this->gcd(that);
    int numerator1_n = that.denominator / gcd * this->numerator;
    int numerator2_n = this->denominator / gcd * that.numerator;
    int numerator = numerator1_n - numerator2_n;
    Fraction result(numerator, gcd);
    return result;
}

Fraction Fraction::times(Fraction that) {
    int num = this->numerator * that.numerator;
    int den = this->denominator * that.denominator;
    Fraction result(num, den);
    // we could call result.reduce() here
    // or use it just before it is necessary
    return result;
}

Fraction Fraction::by(Fraction that){
    int num = this->numerator * that.denominator;
    int den = this->denominator * that.numerator;
    Fraction result(num, den);
    // we could call result.reduce() here
    // or use it just before it is necessary
    return result;
}

int main() {
    auto fraction1 = generate_fraction(1);
    auto fraction2 = generate_fraction(2);
    Fraction result = fraction1.plus(fraction2);
    cout << "Add: " << result.toString() << " is " << result.toDouble() << " in decimal" << endl;
    result = fraction1.minus(fraction2);
    cout << "Sub: " << result.toString() << " is " << result.toDouble() << " in decimal" << endl;
    result = fraction1.times(fraction2);
    cout << "Mult: " << result.toString() << " is " << result.toDouble() << " in decimal" << endl;
    result = fraction1.by(fraction2);
    cout << "Div: " << result.toString() << " is " << result.toDouble() << " in decimal" << endl;
}