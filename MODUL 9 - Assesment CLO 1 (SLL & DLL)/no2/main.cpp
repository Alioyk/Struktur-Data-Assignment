#include "DLLPLaylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    insertLast(L, allocate("Senja di Kota", "Nona Band", 210, 150, 4.2));
    insertLast(L, allocate("Langkahmu", "Delta", 185, 320, 4.8));
    insertLast(L, allocate("Hujan Minggu", "Arka", 240, 90, 3.9));

    viewList(L);

    deleteLast(L);

    updateAtPosition(L, 2);

    viewList(L);

    insertBefore(L, allocate("Senandung", "Mira", 175, 120, 4.0), L.tail);
    updateBefore(L, L.tail->prev);
    deleteBefore(L, L.tail, L.tail->prev);

    searchByPopularityRange(L, 150.0, 300.0);
}
