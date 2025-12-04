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
void PreOrder(address root);   // Soal 3
void PostOrder(address root);  // Soal 3

#endif
