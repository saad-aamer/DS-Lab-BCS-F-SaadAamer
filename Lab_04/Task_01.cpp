#include<iostream>
using namespace std;

void linearSearch(int *arr,int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            cout<<"Key Found at Index "<<i<<endl;
            return;
        }
    }
    cout<<"Key not found!";
    return;
}
int main(){
    const int size=20;
    int *arr= new int[size];
    cout;
    for(int i=0;i<size;i++){
        arr[i]=rand()%21;
    }
    cout<<"Array : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int key;
    cout<<"Enter the Key to search for: ";
    cin>>key;
    linearSearch(arr,size,key);
    delete[] arr;
}