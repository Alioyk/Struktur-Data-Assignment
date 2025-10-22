#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; // dataMahasiswa adalah alias dari struct mahasiswa
typedef struct node *address; // address adalah alias dari pointer ke struct node

struct node // node adalah elemen dari linked list
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist
{
    address first;
};

// function & procedure prototype
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address node_baru);
void insertAfter(linkedlist &List, address node_baru, address prev);
void insertLast(linkedlist &List, address node_baru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void delList(linkedlist &List);

#endif 