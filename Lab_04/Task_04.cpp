#include<iostream>
using namespace std;

void display(int* arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int* arr,int size){
    for(int i=1;i<size;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
}

int main(){
    const int size=10;
    int *arr= new int[size];
    cout;
    for(int i=0;i<size;i++){
        arr[i]=rand()%11;
    }
    cout<<"Unsorted Array : ";
    display(arr,size);
    insertionSort(arr,size);
    cout<<"\nSorted Array : ";
    display(arr,size);
    delete[] arr;
}