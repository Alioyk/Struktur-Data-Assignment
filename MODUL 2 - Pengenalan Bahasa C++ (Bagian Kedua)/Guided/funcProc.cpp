#include <iostream>
using namespace std;

void tulis (int x) {
    for (int i = 1; i <= x; i++) {
        cout << "Baris-" << i << endl;
    }
}

int main() {
    int n;
    cout << "Nilai n: ";
    cin >> n;
    tulis(n);
}