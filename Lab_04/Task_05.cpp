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

void interpolationSearch(int* arr,int size,int key){
    int low=0,high=size-1;
     while(low<=high && key>=arr[low] && key<=arr[high]){
        if(low==high){
            if(arr[low]==key){
                cout<<"\nElement found at index "<<low;
                return;
            }
            break;
        }
        int pos = low + ((double)(key-arr[low])*(high-low))/(arr[high]-arr[low]);

        if(arr[pos]==key){
            cout<<"\nElement found at index "<<pos;
            return;
        }
        if(arr[pos]<key) low=pos+1;
        else high=pos-1;
    }

    cout<<"\nElement not found";
}

int main(){
    const int size=10;
    int *arr=new int[size];

    for(int i=0;i<size;i++){
        arr[i]=rand()%21; 
    }

    cout<<"Unsorted Array : ";
    display(arr,size);

    insertionSort(arr,size);

    cout<<"\nSorted Array : ";
    display(arr,size);

    int key;
    cout<<"\nEnter element to search: ";
    cin>>key;

    interpolationSearch(arr,size,key);

    delete[] arr;
}
