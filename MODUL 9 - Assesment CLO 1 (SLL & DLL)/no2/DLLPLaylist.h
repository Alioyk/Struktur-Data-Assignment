#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating; // 0.0 - 5.0
};

typedef struct Node* address;

struct Node {
    Song info;
    address next;
    address prev;
};

struct List {
    address head;
    address tail;
};

bool isEmpty(List List);
void createList(List &List);
address allocate(string Title, string Artist, int DurationSec, int PlayCount, float Rating);
void deallocate(address &P);
void insertFirst(List &List, address P);
void insertLast(List &List, address P);
void insertAfter(List &List, address P, address Q);
void insertBefore(List &List, address P, address Q);
void deleteFirst(List &List);
void deleteLast(List &List);
void deleteAfter(List &List, address P, address &Q);
void deleteBefore(List &List, address P, address &Q);
void updateAtPosition(List &List, int posisi);
void updateBefore(List &List, address P);
void viewList(List List);
void searchByPopularityRange(List List, float minScore, float maxScore);
// Popularity Score = 0.8 * PlayCount + 20.0 * Rating

#endif