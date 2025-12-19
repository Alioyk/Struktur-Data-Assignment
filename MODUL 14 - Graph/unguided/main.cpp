#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

int main() {
    Graph Z;
    CreateGraph(Z);

    InsertNode(Z, 'A');
    InsertNode(Z, 'B');
    InsertNode(Z, 'C');
    InsertNode(Z, 'D');
    InsertNode(Z, 'E');
    InsertNode(Z, 'F');
    InsertNode(Z, 'G');
    InsertNode(Z, 'H');

    adrNode A = Z.First;
    adrNode B = A->Next;
    adrNode C = B->Next;
    adrNode D = C->Next;
    adrNode E = D->Next;
    adrNode F = E->Next;
    adrNode G = F->Next;
    adrNode H = G->Next;

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, G);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(G, H);

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(Z);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintDFS(Z, A);
    adrNode P = Z.First;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
    PrintBFS(Z, A);
}
