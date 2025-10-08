#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int a = 10, b = 20, c = 30;
    cout << "nilai awal: " << a << ", " << b << ", " << c << endl;
    tukarPointer(&a, &b, &c);
    cout << "nilai setelah tukar pointer: " << a << ", " << b << ", " << c << endl;
    tukarReference(a, b, c);
    cout << "nilai setelah tukar reference: " << a << ", " << b << ", " << c << endl;
}