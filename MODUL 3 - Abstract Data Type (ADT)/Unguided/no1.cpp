#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    int nim;
    float uts, uas, tugas, nilaiAkhir;
};

float nilaiAkhir(mahasiswa m) {
    return (0.3 * m.uts)+(0.4 * m.uas)+(0.3 * m.tugas);
}

int main(){
    mahasiswa m[10];
    int n;
    cout << "Jumlah mahasiswa: ";
    cin >> n;
    for (int i=0; i<n; i++){
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama: ";
        cin >> m[i].nama;
        cout << "NIM: ";
        cin >> m[i].nim;
        cout << "Nilai UTS: ";
        cin >> m[i].uts;
        cout << "Nilai UAS: ";
        cin >> m[i].uas;
        cout << "Nilai tugas: ";
        cin >> m[i].tugas;
        m[i].nilaiAkhir = nilaiAkhir(m[i]);
    }
    cout << "Nilai akhir:" << endl;
    for (int i=0; i<n; i++){
        cout << m[i].nama << " (" << m[i].nim << ") = " << m[i].nilaiAkhir << endl;
    }
}