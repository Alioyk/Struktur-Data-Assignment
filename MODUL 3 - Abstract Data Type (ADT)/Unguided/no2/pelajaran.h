#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
#include <iostream>
using namespace std;

struct pelajaran
{
    string nama_mapel;
    string kode_mapel;

};
pelajaran create_pelajaran(string nama_mapel, string kode_mapel);
void tampil_pelajaran(pelajaran pel);

#endif // PELAJARAN_H_INCLUDED