#include<iostream>
using namespace std;

class heap {
    int *arr;
    int size, capacity;
    

public:
    heap(int cap) {
        capacity = cap;
        size = 0;
        
        arr = new int[capacity];
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i){
        while(arr[parent(i)]<arr[i]){
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }
   void heapifyDown(int i) {
    int largest = i;
    int l = left(i);
    int r = right(i);

    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyDown(largest);
    }
}

    void insert(int val){
        if(size==capacity)return;
        arr[size]=val;
        size++;
        heapifyUp(size-1);
    }
    int deleteRoot(){
        if(size==0) return -1;

        int rootVal=arr[0];
        arr[0]=arr[size-1];
        size--;
        heapifyDown(0);
        return rootVal;
    }
     void display() {
       cout<<"Max Heap: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    int * sortedMaxHeap(){
        int* sorted=new int[capacity];
        for(int i=0;i<size;i++){
            sorted[i]=deleteRoot();
        }
        
        return sorted;
    }
    void findKthLargest(int k){
        int *p=sortedMaxHeap();
        cout<<k<<"th Largest: "<<*(p+(k-1))<<endl;
    }
};

int main(){
heap maxH(20);
    int arr[7]={1, 23, 12, 9, 30, 2, 50};
    for(int i=0;i<7;i++) maxH.insert(arr[i]);
    maxH.display();
    maxH.findKthLargest(3);

    heap maxH2(20);
     int arr2[5]={12, 3, 5, 7, 19};
   for(int i=0;i<5;i++) maxH2.insert(arr2[i]);
    maxH2.display();
    maxH2.findKthLargest(2);
}w