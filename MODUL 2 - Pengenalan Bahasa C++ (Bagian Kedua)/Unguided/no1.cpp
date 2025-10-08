#include <iostream>
using namespace std;

void isiMatriks(int M[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> M[i][j];
        }
    }
}

void penjumlahanM(int A[3][3], int B[3][3], int C[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void penguranganM(int A[3][3], int B[3][3], int C[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void perkalianM(int A[3][3], int B[3][3], int C[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

void hasilMatriks(int M[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[3][3], B[3][3], C[3][3];
    cout << "Matriks 1:" << endl;
    isiMatriks(A);
    cout << "Matriks 2:" << endl;
    isiMatriks(B);

    cout << "Hasil Penjumlahan:" << endl;
    penjumlahanM(A, B, C);
    hasilMatriks(C);
    cout << "Hasil Pengurangan:" << endl;
    penguranganM(A, B, C);
    hasilMatriks(C);
    cout << "Hasil Perkalian:" << endl;
    perkalianM(A, B, C);
    hasilMatriks(C);
}