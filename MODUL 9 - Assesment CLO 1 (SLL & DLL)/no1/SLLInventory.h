#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H
#define Nil NULL

#include <iostream>
using namespace std;

struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

typedef struct Node* address;

struct Node {
    Product info;
    address next;
};

struct List {
    address first;
};

bool isEmpty(List List);
void createList(List &List);
address allocate(string Nama, string SKU, int Jumlah, float HargaSatuan, float DiskonPersen);
void deallocate(address &addr);
void insertFirst(List &List, address P);
void insertLast(List &List, address P);
void insertAfter(List &List, address P, address Q);
void deleteFirst(List &List);
void deleteLast(List &List);
void deleteAfter(List &List, address P, address &Q);
void updateAtPosition(List &List, int posisi);
void viewList(List List);
void searchByFinalPriceRange(List List, float minPrice, float maxPrice);
void MaxHargaAkhir(List List);

#endif
