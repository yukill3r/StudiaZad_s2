#include <iostream>
using namespace std;

class drzewo{
    public:
        virtual void draw(){};
};

class drzewo_1 : public drzewo{
    public:
        void draw(){
            cout << " /\\" << endl << "//\\\\" << endl;
        }
};

class drzewo_2 : public drzewo{
    public:
        void draw(){
            cout << " /\\" << endl << "/**\\" << endl;
        }
};

class drzewo_3 : public drzewo{
    public:
        void draw(){
            cout << " /\\" << endl << "/++\\" << endl;
        }
};

int main() {
    drzewo_1 drzewo1;
    drzewo_2 drzewo2;
    drzewo_3 drzewo3;
    drzewo* arr [3] = {&drzewo1, &drzewo2, &drzewo3};

    for (drzewo *s:arr){
        s->draw();
    }

    return 0;
}