#include "SLLInventory.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    insertLast(L, allocate("Pulpen", "A001", 20, 2500, 0));
    insertLast(L, allocate("Buku Tulis", "A002", 15, 5000, 10));
    insertLast(L, allocate("Penghapus", "A003", 30, 1500, 0));

    viewList(L);

    deleteFirst(L);

    viewList(L);

    updateAtPosition(L, 2);

    viewList(L);

    searchByFinalPriceRange(L, 2000, 7000);

    MaxHargaAkhir(L);
}