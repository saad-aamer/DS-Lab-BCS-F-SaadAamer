#include<iostream>
using namespace std;

void display(int* arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void combSort(int* arr,int size){
    int gap=size;
    bool swapped=true;

    while(gap!=1 || swapped){
        gap=(gap*10)/13;
        if(gap<1) gap=1;

        swapped=false;
        for(int i=0;i+gap<size;i++){
            if(arr[i]>arr[i+gap]){
                int temp=arr[i];
                arr[i]=arr[i+gap];
                arr[i+gap]=temp;
                swapped=true;
            }
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
    combSort(arr,size);
    cout<<"\nSorted Array : ";
    display(arr,size);
    delete[] arr;
}