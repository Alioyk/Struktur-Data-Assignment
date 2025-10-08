#include <iostream>
using namespace std;

int cariMaksimum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
void hitungRataRata(int arr[], int n) {
    int jml = 0;
    for (int i = 0; i < n; i++) {
        jml += arr[i];
    }
    cout << "nilai rata-rata: " << (float)jml/n << endl;
}
void tampilArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int n = 10;
    int arrA[n] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilih;

    do {
        cout << "--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. cari nilai maksimum" << endl;
        cout << "3. cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata - rata" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tampilArray(arrA, n);
                break;
            case 2:
                cout << "nilai maksimum: " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "nilai minimum: " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                hitungRataRata(arrA, n);
                break;
            default:
                return 0;
        }
        cout << endl;
    } while (pilih == 1 || pilih == 2 || pilih == 3 || pilih == 4);
}