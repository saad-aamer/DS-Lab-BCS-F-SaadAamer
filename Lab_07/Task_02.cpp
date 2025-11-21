#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int exp) {
    int output[1000];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > mx){
            mx = arr[i];
        }
    }

    for (int exp = 1; mx / exp > 0; exp *= 10){
        countingSort(arr, n, exp);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original: ";
    printArray(arr, n);
    int asc[100];
    for (int i = 0; i < n; i++) asc[i] = arr[i];
    radixSort(asc, n);
    cout << "\nAscending: ";
    printArray(asc, n);
    int desc[100];
    for (int i = 0; i < n; i++)
        desc[i] = asc[n - 1 - i];
    cout << "Descending: ";
    printArray(desc, n);

    return 0;
}
