#include<iostream>
using namespace std;

void display(int** arr,int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
        cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void reducedForm(int** arr, int row, int col){
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=0){
                cout<<"Row: "<<i<<" Col: "<<j<<" Value: "<<arr[i][j]<<endl;
            }
        }
        
    }
    
}
int main(){
    int row,col;
    cout<<"Number of Rows? ";
    cin>>row;
    cout<<"Number of Cols? ";
    cin>>col;
    int** arr=new int*[row];
    for(int i=0;i<row;i++){
        arr[i]=new int[col];
    }
    cout<<"Enter Elements in Matrix: "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Original Matrix: "<<endl;
    display(arr,row,col);
    cout<<"Reduced Form: "<<endl;
    reducedForm(arr,row,col);

    for(int i=0;i<row;i++){
        delete[] arr[i];
    }
    delete[] arr;
}