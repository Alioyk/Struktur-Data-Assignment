#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan dataKendaraan;
typedef struct elmlist *address;

struct elmlist {
    dataKendaraan info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

// Nomer 1
void createList(List &L);
address alokasi(dataKendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
// Nomer 2
address findElm(List L, string nopol);
// Nomer 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
#endif