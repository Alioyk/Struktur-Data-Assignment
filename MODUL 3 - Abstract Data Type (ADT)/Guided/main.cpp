#include <iostream>
#include <mahasiswa.h>
using namespace std;

int main() {
    mahasiswa mhs;
    inputData(mhs);
    cout << "rata-rata = " << hitungRataRata(mhs);
    return 0;
}