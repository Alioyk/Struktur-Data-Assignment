#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    for (int i = x; i > 0; i--)
    {
        for (int j = 0; j < x-i; j++)
        {
            cout << "  ";
        }
        for (int k = i; k > 0; k--)
        {
            cout << k << " ";
        }
        cout << "* ";
        for (int l = 1; l <= i; l++)
        {
            cout << l << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < x; i++)
    {
        cout << "  ";
    }
    cout << "*" << endl;
}