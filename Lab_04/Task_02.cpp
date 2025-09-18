#include<iostream>
using namespace std;

void display(int* arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(int *arr,int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

}

int main(){
    const int size=20;
    int *arr= new int[size];
    cout;
    for(int i=0;i<size;i++){
        arr[i]=rand()%21;
    }
    cout<<"Unsorted Array : ";
    display(arr,size);
    bubbleSort(arr,size);
    cout<<"\nSorted Array : ";
    display(arr,size);
    delete[] arr;
}