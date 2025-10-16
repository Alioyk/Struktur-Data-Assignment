#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string nama_mapel, string kode_mapel) {
    pelajaran pel;
    pel.nama_mapel = nama_mapel;
    pel.kode_mapel = kode_mapel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.nama_mapel << endl;
    cout << "nilai : " << pel.kode_mapel << endl;
}