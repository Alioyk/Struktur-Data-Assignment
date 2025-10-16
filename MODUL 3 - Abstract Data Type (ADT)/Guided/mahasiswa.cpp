#include <iostream>
using namespace std;
#include "mahasiswa.h"

void inputData(mahasiswa &m) {
    cout << "input nama = ";
    cin >> m.nim;
    cout << "input nilai = ";
    cin >> m.nilai;
    cout << "input nilai2 = ";
    cin >> m.nilai2;
    
}

float hitungRataRata(mahasiswa m) {
    return (m.nilai + m.nilai2) / 2.0;
}