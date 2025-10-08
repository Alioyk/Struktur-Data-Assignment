#include <iostream>
using namespace std;

void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 20, b = 50;
    int *ptr = &a;

    cout << "Nilai A dan B: " << a << " dan " << b << endl;
    cout << "Alamat A: " << &a << endl;
    cout << "Nilai PTR: " << ptr << endl;
    cout << "Nilai yang ditunjuk PTR: " << *ptr << "\n\n";

    cout << "Tukar nilai A dan B" << endl;
    tukar(&a, &b);
    cout << "Nilai A dan B setelah ditukar: " << a << " dan " << b << endl;
}