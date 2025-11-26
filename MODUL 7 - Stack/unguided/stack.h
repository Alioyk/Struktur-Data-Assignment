#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype* info[20];
    int top;
};

// Nomer 1
void createStack(Stack& S);
void push(Stack& S, infotype x);
infotype pop(Stack& S);
void printInfo(Stack& S);
void balikStack(Stack& S);

// Nomer 2
void pushAscending(Stack& S, int x);

// Nomer 3
void getInputStream(Stack& S);
#endif