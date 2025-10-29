#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah
{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; // dataBuah adalah alias dari struct buah
typedef struct node *address; // address adalah alias dari pointer ke struct node

struct node // node adalah elemen dari linked list
{
    dataBuah isidata;
    address next;
};

struct linkedlist
{
    address first;
};

// modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address node_baru);
void insertAfter(linkedlist &List, address node_baru, address prev);
void insertLast(linkedlist &List, address node_baru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// modul 5 - update
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

// modul 5 - search
void findByData(linkedlist List, string nama);
void findByAddress(linkedlist List, address node);
void findByRange(linkedlist List, float hargaMin, float hargaMax);
#endif 