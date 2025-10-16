#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa
{
    char nim[10];
    int nilai, nilai2;
};

void inputData(mahasiswa &m);
float hitungRataRata(mahasiswa m);
#endif // MAHASISWA_H_INCLUDED
