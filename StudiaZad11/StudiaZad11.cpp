#include <iostream>
#include <string>
using namespace std;

class Square {
    public:
        Square(double side);
        
        void set_side(int value){
            if (value>0){
                this->side = value;
                this->update_area();
            } else {
                this->side = 0;
                this->update_area();
            }
        }
        void update_area(){
            this->area = this->get_side() * this->get_side();
        }
        int get_area(){
            return this->area;
        }
        int get_side(){
            return this->side;
        }
    private:
        double side;
        double area;
    // Your code here
    };

Square::Square(double side){
    this->side = side;
    this->area = side * side;
    }

void print(Square* square){
    cout << "Square: side=" << square->get_side() << " area=" << square->get_area() << endl;
    }

int main(){
    Square s(4);
    print(&s);
    s.set_side(2.0);
    print(&s);
    s.set_side(-33.0);
    print(&s);
    return 0;
}