#include "Doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    dataKendaraan data;
    address P;
    createList(L);

    // Nomor 1
    int i = 1;
    while (i <= 4) {
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;
        
        bool found = false;
        P = L.first;
        while (P != Nil) {
            if (P->info.nopol == data.nopol) {
                cout << "nomor polisi sudah terdaftar" << endl;
                found = true;
                break;
            }
            P = P->next;
        }
        if (!found) {
            P = alokasi(data);
            insertLast(L, P);
        }
        cout << endl;
        i++;
    }
    printInfo(L);

    // Nomor 2
    string cari;
    cout << "\nMasukkan nomor polisi yang dicari  : ";
    cin >> cari;
    P = findElm(L, cari);
    if (P != Nil) {
        cout << "\nNomor Polisi\t: " << P->info.nopol << endl;
        cout << "Warna\t\t: " << P->info.warna << endl;
        cout << "Tahun\t\t: " << P->info.thnBuat << endl;
    } else {
        cout << "Nomor tidak ditemukan" << endl;
    }

    // Nomor 3
    cout << "\nMasukkan nomor polisi yang akan dihapus  : ";
    cin >> cari;
    P = findElm(L, cari);
    if (P != Nil) {
        if (P == L.first) {
            deleteFirst(L, P);
        } else if (P == L.last) {
            deleteLast(L, P);
        } else {
            address Q = L.first;
            while (Q->next != P) {
                Q = Q->next;
            }
            deleteAfter(Q, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << cari << " berhasil dihapus." << endl;
    } else {
        cout << "Nomor tidak ditemukan" << endl;
    }
    printInfo(L);
}