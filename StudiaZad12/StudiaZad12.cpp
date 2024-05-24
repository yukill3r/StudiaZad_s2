#include <string> 
#include <iostream>
#include <sstream>

class AdHocSquare {
    public:
        AdHocSquare(double side);
        void set_side(double side);
        double get_area();
    private:
        double side;
};

AdHocSquare::AdHocSquare(double side){
    this->side = side;
}
void AdHocSquare::set_side(double side){
    this->side = side;
}
double AdHocSquare::get_area(){
    return this->side*2;
}

class LazySquare {
    public:
        LazySquare(double side);
        void set_side(double side);
        double get_area();
    private:
        double side;
        double area;
        bool side_changed;
};

LazySquare::LazySquare(double side){
    this->side = side;
}
void LazySquare::set_side(double side){
    this->side = side;
    this->area = side * side;
}
double LazySquare::get_area(){
    return this->area;
}


int main() {
    double test = 4.0;
    LazySquare ls(test);
};
