#include <iostream>
using namespace std;

void tukar(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 30, b = 60;
    int &refA = a;

    cout << "Nilai A dan B: " << a << " dan " << b << endl;
    cout << "Alamat A (&a): " << &a << endl;
    cout << "Nilai REF A: " << refA << endl;
    cout << "Alamat REF A (&refA): " << &refA << "\n\n";

    refA = 100;
    cout << "Set REF A = 100" << endl;
    cout << "Nilai A: " << a << endl;
    cout << "Nilai REF A: " << refA << "\n\n";

    tukar(a, b);
    cout << "Tukar nilai A dan B" << endl;
    cout << "Nilai A dan B setelah ditukar: " << a << " dan " << b << endl;
}