#include "SLLInventory.h"
#include <iostream>
using namespace std;

bool isEmpty(List List) {
    return (List.first == Nil);
}

void createList(List &List) {
    List.first = Nil;
}

address allocate(string Nama, string SKU, int Jumlah, float HargaSatuan, float DiskonPersen) {
    address P = new Node;
    P->info.Nama = Nama;
    P->info.SKU = SKU;
    P->info.Jumlah = Jumlah;
    P->info.HargaSatuan = HargaSatuan;
    P->info.DiskonPersen = DiskonPersen;
    P->next = Nil;
    return P;
}

void deallocate(address &addr) {
    addr->next = Nil;
    delete addr;
}

void insertFirst(List &List, address P) {
    P->next = List.first;
    List.first = P;
}

void insertLast(List &List, address P) {
    if (isEmpty(List)) {
        List.first = P;
    } else {
        address Q = List.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(List &List, address P, address Q) {
    if (Q != Nil) {
        P->next = Q->next;
        Q->next = P;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void deleteFirst(List &List) {
    address P;
    if (isEmpty(List) == false) {
        P = List.first;
        List.first = List.first->next;
        P->next = Nil;
        deallocate(P);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void deleteLast(List &List) {
    address P, Q;
    if (isEmpty(List) == false) {
        P = List.first;
        if (P->next == Nil) {
            List.first = Nil;
            deallocate(P);
        } else {
            while (P->next != Nil) {
                Q = P;
                P = P->next;
            }
            Q->next = Nil;
            deallocate(P);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void deleteAfter(List &List, address P, address &Q) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (Q != Nil && Q->next != Nil) {
            P = Q->next;
            Q->next = P->next;
            P->next = Nil;
            deallocate(P);
            cout << "Node setelah node " << Q->info.Nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void updateAtPosition(List &List, int posisi) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address P = List.first;
        int idx = 1;
        while (P != Nil && idx < posisi) {
            P = P->next;
            idx++;
        }
        if (P != Nil) {
            cout << "Masukkan update data pada posisi ke-" << posisi << endl;
            cout << "Nama Produk : ";
            cin >> P->info.Nama;
            cout << "SKU : ";
            cin >> P->info.SKU;
            cout << "Jumlah : ";
            cin >> P->info.Jumlah;
            cout << "Harga Satuan : ";
            cin >> P->info.HargaSatuan;
            cout << "Diskon Persen : ";
            cin >> P->info.DiskonPersen;
            cout << "Data Berhasil Diupdate!" << endl;
        } else {
            cout << "Posisi tidak valid!" << endl;
        }
    }
}

void viewList(List List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address P = List.first;
        int idx = 1;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (P != Nil) {
            cout << "Posisi ke-" << idx << endl;
            cout << "Nama Produk : " << P->info.Nama << endl;
            cout << "SKU : " << P->info.SKU << endl;
            cout << "Jumlah : " << P->info.Jumlah << endl;
            cout << "Harga Satuan : " << P->info.HargaSatuan << endl;
            cout << "Diskon Persen : " << P->info.DiskonPersen << "%" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            P = P->next;
            idx++;
        }
    }
}

void searchByFinalPriceRange(List List, float minPrice, float maxPrice) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address P = List.first;
        int idx = 1;
        bool found = false;
        cout << "Produk Dengan Harga Akhir " << minPrice << " - " << maxPrice << " :" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (P != Nil) {
            float finalPrice = P->info.HargaSatuan * (1 - P->info.DiskonPersen/100);
            if (finalPrice >= minPrice && finalPrice <= maxPrice) {
                cout << "Posisi ke-" << idx << endl;
                cout << "Nama Produk : " << P->info.Nama << endl;
                cout << "Harga Akhir : " << finalPrice << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                found = true;
            }
            P = P->next;
            idx++;
        }
        if (!found) {
            cout << "Tidak ada produk dalam range harga tersebut" << endl;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
}

void MaxHargaAkhir(List List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address P = List.first;
        float maxPrice = 0.0;
        while (P != Nil) {
            float finalPrice = P->info.HargaSatuan * (1 - P->info.DiskonPersen/100);
            if (finalPrice > maxPrice) {
                maxPrice = finalPrice;
            }
            P = P->next;
        }
        cout << "Produk dengan Harga Akhir Terbesar : " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        P = List.first;
        int idx = 1;
        while (P != Nil) {
            float finalPrice = P->info.HargaSatuan * (1 - P->info.DiskonPersen/100);
            if (finalPrice == maxPrice) {
                cout << "Posisi ke-" << idx << endl;
                cout << "Nama Produk : " << P->info.Nama << endl;
                cout << "SKU : " << P->info.SKU << endl;
                cout << "Jumlah : " << P->info.Jumlah << endl;
                cout << "Harga Satuan : " << P->info.HargaSatuan << endl;
                cout << "Diskon Persen : " << P->info.DiskonPersen << "%" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            }
            P = P->next;
            idx++;
        }
    }
}