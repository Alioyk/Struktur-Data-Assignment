#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new elmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

//

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        L.First = L.First->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    address Q = L.First;
    if (Q != Nil) {
        if (Q->next == Nil){
            L.First = Nil;
            P = Q;
        } else {
            while (Q->next->next != Nil){
                Q = Q->next;
            }
            P = Q->next;
            Q->next = Nil;
        }
    }
}

void deleteAfter(List &L, address &P){
    address Q = L.First;
    while (Q != Nil){
        if (Q->next->info == P->info){
            Q->next = P->next;
            P->next = Nil;
            break;
        }
        Q = Q->next;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}