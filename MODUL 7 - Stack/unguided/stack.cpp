#include "stack.h"
#include <iostream>
using namespace std;

// Nomer 1
void createStack(Stack& S) {
    S.top = -1;
}
void push(Stack& S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = new infotype;
        *(S.info[S.top]) = x;
    } else {
        cout << "stack penuh" << endl;
    }
}
infotype pop(Stack& S) {
    if (S.top >= 0) {
        infotype x = *(S.info[S.top]);
        delete S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "stack kosong" << endl;
        return -1;
    }
}
void printInfo(Stack& S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        int x = *(S.info[i]);
        if (x >= 0 && x <= 9) {
            cout << x << " ";
        } else {
            cout << char(x) << " ";
        }
    }
    cout << endl;
}
void balikStack(Stack& S) {
    Stack temp;
    createStack(temp);

    while (S.top != -1) {
        infotype x = pop(S);
        push(temp, x);
    }

    S = temp;
}

// Nomer 2
void pushAscending(Stack& S, int x) {
    Stack temp;
    createStack(temp);

    while (S.top != -1 && *(S.info[S.top]) > x) {
        push(temp, pop(S));
    }
    push(S, x);
    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

// Nomer 3
void getInputStream(Stack& S) {
    char c;
    while (true) {
        c = cin.get();
        if (c == '\n') {
            break;
        }
        push(S, c);
    }
}