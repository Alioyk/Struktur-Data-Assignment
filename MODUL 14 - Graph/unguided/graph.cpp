#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

void CreateGraph(Graph &G) {
    G.First = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode p = new ElmNode;
    p->info = X;
    p->visited = 0;
    p->firstEdge = NULL;
    p->Next = NULL;

    if (G.First == NULL) {
        G.First = p;
    } else {
        adrNode q = G.First;
        while (q->Next != NULL) {
            q = q->Next;
        }
        q->Next = p;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->Node = N2;
    E1->Next = NULL;
    if (N1->firstEdge == NULL) {
        N1->firstEdge = E1;
    } else {
        adrEdge P = N1->firstEdge;
        while (P->Next != NULL) {
            P = P->Next;
        }
        P->Next = E1;
    }
    adrEdge E2 = new ElmEdge;
    E2->Node = N1;
    E2->Next = NULL;
    if (N2->firstEdge == NULL) {
        N2->firstEdge = E2;
    } else {
        adrEdge Q = N2->firstEdge;
        while (Q->Next != NULL) {
            Q = Q->Next;
        }
        Q->Next = E2;
    }
}


void PrintInfoGraph(Graph G) {
    adrNode p = G.First;
    while (p != NULL) {
        cout << p->info << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->Node->info << " ";
            e = e->Next;
        }
        cout << endl;
        p = p->Next;
    }
}

//Nomer 2
void PrintDFS(Graph G, adrNode N) {
    stack<adrNode> S;
    S.push(N);
    N->visited = 1;

    cout << "DFS Traversal: ";
    while (!S.empty()) {
        adrNode current = S.top();
        S.pop();
        cout << current->info << " - ";

        adrEdge e = current->firstEdge;
        while (e != NULL) {
            if (e->Node->visited == 0) {
                e->Node->visited = 1;
                S.push(e->Node);
            }
            e = e->Next;
        }
    }
    cout << endl;
}

//Nomer 3
void PrintBFS(Graph G, adrNode N) {
    queue<adrNode> Q;
    Q.push(N);
    N->visited = 1;

    cout << "BFS Traversal: ";
    while (!Q.empty()) {
        adrNode current = Q.front();
        Q.pop();
        cout << current->info << " - ";

        adrEdge e = current->firstEdge;
        while (e != NULL) {
            if (e->Node->visited == 0) {
                e->Node->visited = 1;
                Q.push(e->Node);
            }
            e = e->Next;
        }
    }
    cout << endl;
}