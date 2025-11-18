#include<iostream>
using namespace std;

void display(int* arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void shellSort(int* arr,int size){
    for(int gap=size/2;gap>0;gap/=2){
        for(int i=gap;i<size;i++){
            int temp=arr[i];
            int j=i;
            while(j>=gap && arr[j-gap]>temp){
                arr[j]=arr[j-gap];
                j-=gap;
            }
            arr[j]=temp;
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
    shellSort(arr,size);
    cout<<"\nSorted Array : ";
    display(arr,size);
    delete[] arr;
}