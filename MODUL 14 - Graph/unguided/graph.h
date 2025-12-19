#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;
//Nomer 1
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited; 
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
//Nomer 2
void PrintDFS(Graph G, adrNode N);
//Nomer 3
void PrintBFS(Graph G, adrNode N);

#endif