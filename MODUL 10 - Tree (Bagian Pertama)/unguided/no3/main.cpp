#include "bstree.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    address root = Nil;
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 7);

    cout << "pre-order : ";
    PreOrder(root);
    cout << endl;

    cout << "post-order : ";
    PostOrder(root);
    cout << endl;

    return 0;
}
