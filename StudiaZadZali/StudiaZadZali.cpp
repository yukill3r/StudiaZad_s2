#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class Figura {
    public:
        Figura();
        Figura(double a);
        double Pole_pow;
        virtual void Oblicz_pole();
        void Ustaw_a(double x);
        double Get_a();
    private:
        double Bok_a;

};

Figura::Figura(){

}

Figura::Figura(double a){
    this->Ustaw_a(a);
    this->Oblicz_pole();
}

void Figura::Ustaw_a(double x) {
    this->Bok_a = x;
    this->Oblicz_pole();
}

void Figura::Oblicz_pole(){
    this->Pole_pow = pow(this->Bok_a, 2);
}

double Figura::Get_a(){
    return this->Bok_a;
}

class Prostokat : public Figura{
    public:
        Prostokat(double a, double b);
        void Oblicz_pole();

    private:
        double Bok_b;
};

Prostokat::Prostokat(double a, double b){
    this->Bok_b = b;
    this->Ustaw_a(a);
    this->Oblicz_pole();
}

void Prostokat::Oblicz_pole(){
    this->Pole_pow = this->Bok_b * this->Get_a();
}

int main() {
    Figura figura1;
    Figura figura2(4.0);
    figura1.Ustaw_a(3.5);
    Prostokat prostokat(3.0, 4.5);
    
    cout << figura1.Pole_pow << endl <<  figura2.Pole_pow << endl;
    cout << prostokat.Pole_pow;
}