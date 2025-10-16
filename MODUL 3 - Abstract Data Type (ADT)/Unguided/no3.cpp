#include <iostream>
using namespace std;

void tampil_array(string arr[3][3]) {
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void tukar_array(string A1[3][3], string A2[3][3], int x, int y) {
    string temp = A1[x][y];
    A1[x][y] = A2[x][y];
    A2[x][y] = temp;
}
void tukar_pointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){
    string A[3][3] = {{"P","C","B"},{"M","O","F"},{"U","F","O"}};
    string B[3][3] = {{"1","2","3"},{"4","5","6"},{"7","8","9"}};
    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;

    cout << "Array A:" << endl;
    tampil_array(A);
    cout << "Array B:" << endl;
    tampil_array(B);

    tukar_array(A,B, 2,2);
    cout << "Tukar A[2][2] dengan B[2][2]" << endl;
    cout << "Array A:" << endl;
    tampil_array(A);
    cout << "Array B:" << endl;
    tampil_array(B);

    cout << "Sebelum tukar pointer" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    tukar_pointer(p1, p2);
    cout << "Setelah tukar pointer" << endl;
    cout << "x = " << x << ", y = " << y << endl;
}