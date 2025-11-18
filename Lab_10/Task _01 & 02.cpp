#include <iostream>
using namespace std;

class heap {
    int *arr;
    int size, capacity;
    bool isMaxHeap;

public:
    heap(int cap, bool type) {
        capacity = cap;
        size = 0;
        isMaxHeap = type;
        arr = new int[capacity];
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    bool compare(int p, int c) {
        return isMaxHeap ? p < c : p > c;
    }

    void heapifyUp(int i) {
        while (i > 0 && compare(arr[parent(i)], arr[i])) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int extreme = i;
        int l = left(i);
        int r = right(i);

        if (l < size && compare(arr[extreme], arr[l]))
            extreme = l;
        if (r < size && compare(arr[extreme], arr[r]))
            extreme = r;

        if (extreme != i) {
            swap(arr[i], arr[extreme]);
            heapifyDown(extreme);
        }
    }

    void insert(int val) {
        if (size == capacity) return;
        arr[size] = val;
        size++;
        heapifyUp(size - 1);
    }

    int deleteRoot() {
        if (size == 0) return -1;

        int rootVal = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return rootVal;
    }

    void update(int index, int val) {
        if (index >= size) return;
        int old = arr[index];
        arr[index] = val;
        if (compare(old, val)) 
            heapifyUp(index);
        else 
            heapifyDown(index);
    }

    void sort() {
        int* sorted = new int[size];
        int originalSize = size;

        for (int i = 0; i < originalSize; i++)
            sorted[i] = deleteRoot();

        cout << (isMaxHeap ? "Max Heap Sorted: " : "Min Heap Sorted: ");
        for (int i = 0; i < originalSize; i++)
            cout << sorted[i] << " ";
        cout << endl;

        delete[] sorted;
    }

    
void isBinaryHeap() {
    bool isBinHeap = true;

    for (int i = 0; i < size; i++) {
        int l = left(i);
        int r = right(i);

       
        if (l < size && ((isMaxHeap && arr[i] < arr[l]) || (!isMaxHeap && arr[i] > arr[l]))) {
            isBinHeap = false;
            break;
        }

     
        if (r < size && ((isMaxHeap && arr[i] < arr[r]) || (!isMaxHeap && arr[i] > arr[r]))) {
            isBinHeap = false;
            break;
        }
    }

    cout << (isBinHeap ? "Is Binary Heap" : "Is Not Binary Heap") << endl;
}

    

    void display() {
        cout << (isMaxHeap ? "Max Heap: " : "Min Heap: ");
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    heap maxH(20, true);
    maxH.insert(8);
    maxH.insert(7);
    maxH.insert(6);
    maxH.insert(5);
    maxH.insert(4);
    maxH.display();

    maxH.update(2, 10);
    maxH.display();

    maxH.deleteRoot();
    maxH.display();
    maxH.isBinaryHeap();

    cout << endl;

    heap minH(20, false);
    minH.insert(8);
    minH.insert(7);
    minH.insert(6);
    minH.insert(5);
    minH.insert(4);
    minH.display();

    minH.update(1, 2);
    minH.display();

    minH.deleteRoot();
    minH.display();
    minH.isBinaryHeap();

    minH.sort();
}
