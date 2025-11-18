#include<iostream>
using namespace std;

void addExpenses(int *arr,int size){
    cout<<"Enter Monthly Expenses: "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}
void display(int*arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void calculateAvg(int*arr,int size){
    int sum=0,avg;
    for(int i=0;i<size;i++){
       sum+=arr[i];
    }
    avg=sum/size;
    cout<<"Average Monthly Expenses = "<<avg<<endl;
}
void addMonths(int*&arr,int &size,int newSize){
    int *newArr=new int[newSize];
    for(int i=0;i<size;i++){
        newArr[i]=arr[i];
    }
     for(int i=size;i<newSize;i++){
        newArr[i]=0;
    }
    cout<<"Enter Expenses for Additional Months: "<<endl;
    for(int i=size;i<newSize;i++){
        cin>>newArr[i];
    }
    delete[] arr;
    arr=newArr;
    size=newSize;
}
int main(){
    int size;
    cout<<"Number of Months? ";
    cin>>size;
    int* monthlyExpenses=new int[size];
    addExpenses(monthlyExpenses,size);
    display(monthlyExpenses,size);
    calculateAvg(monthlyExpenses,size);
    int newSize;
    cout<<"Enter Number of New Months : ";
    cin>>newSize;
    addMonths(monthlyExpenses,size,newSize);
    calculateAvg(monthlyExpenses,size);
    delete[] monthlyExpenses;
    

}