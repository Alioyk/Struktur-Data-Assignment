#include "circularlist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.First = nullptr;
}

address createList(string nama, string nim, char jenis_kelamin, float ipk) {
    address P = new ElmList;
    P->info.nama = nama;
    P->info.nim = nim;
    P->info.jenis_kelamin = jenis_kelamin;
    P->info.ipk = ipk;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        P->next = P;
    } else {
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        P->next = L.First;
        L.First = P;
        last->next = L.First;
    }
}

void insertAfter(List &L, address Prec, address P) {
    P->next = Prec->next;
    Prec->next = P;
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        P->next = P;
    } else {
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        last->next = P;
        P->next = L.First;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.First != nullptr) {
        P = L.First;
        if (P->next == L.First) {
            L.First = nullptr;
        } else {
            address last = L.First;
            while (last->next != L.First) {
                last = last->next;
            }
            L.First = P->next;
            last->next = L.First;
        }
        P->next = nullptr;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = nullptr;
}

void deleteLast(List &L, address &P) {
    if (L.First != nullptr) {
        address last = L.First;
        address prev = nullptr;
        while (last->next != L.First) {
            prev = last;
            last = last->next;
        }
        P = last;
        if (prev == nullptr) {
            L.First = nullptr;
        } else {
            prev->next = L.First;
        }
        P->next = nullptr;
    }
}

address findElm(List L, mahasiswa x) {
    if (L.First == nullptr) {
        return nullptr;
    }
    address P = L.First;
    do {
        if (P->info.nim == x.nim) {
            return P;
        }
        P = P->next;
    } while (P != L.First);
    return nullptr;
}

void printInfo(List L){
    if (L.First == nullptr) {
        cout << "list kosong" << endl;
        return;
    }
    address P = L.First;
    do {
        cout << "Nama : " << P->info.nama << "\nNIM : " << P->info.nim <<"\nL/P : " << P->info.jenis_kelamin << "\nIPK : " << P->info.ipk << "\n\n";
        P=P->next;
    } while (P != L.First);
}

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    address P = new ElmList;
    P->info.nama = nama;
    P->info.nim = nim;
    P->info.jenis_kelamin = jenis_kelamin;
    P->info.ipk = ipk;
    P->next = nullptr;
    return P;
}