#include <iostream>
using namespace std;

void heapifyDown(int arr[], int n, int i) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapifyDown(arr, n, largest);
    }
}

void convertMinToMaxHeap(int arr[], int n) {
    for (int i = (n/2)-1; i >= 0; i--) {
        heapifyDown(arr, n, i);
    }
}

int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Min Heap Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<"\n(After Conversion)\n";
    convertMinToMaxHeap(arr, n);

    cout << "Max Heap Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
