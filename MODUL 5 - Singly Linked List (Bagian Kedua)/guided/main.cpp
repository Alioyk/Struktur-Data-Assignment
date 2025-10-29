#include "buah.h"
#include <iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtbuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 48, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl << endl;

    findByData(List, "Kelapa");
    findByAddress(List, nodeC);
    findByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DELETE LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl << endl;

    return 0;
}