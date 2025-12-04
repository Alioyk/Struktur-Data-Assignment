#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

typedef int infotype;

typedef struct Node *address;
struct Node {
    infotype info;
    address left;
    address right;
};

// Soal 1
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);

// Soal 2
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

// Soal 3
void PreOrder(address root);
void PostOrder(address root);

#endif
