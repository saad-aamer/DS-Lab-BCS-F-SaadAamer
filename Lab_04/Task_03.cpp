#include<iostream>
using namespace std;

void display(int* arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void selectionSort(int *arr,int size){
    for(int i=0;i<size-1;i++){
        int min=i;
        for(int j=i+1;j<size;j++){
            
            if(arr[j]<arr[min]){
                min=j;
            }
           int temp=arr[min];
           arr[min]=arr[i];
           arr[i]=temp;
        }
        
        

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
    selectionSort(arr,size);
    cout<<"\nSorted Array : ";
    display(arr,size);
    delete[] arr;
}