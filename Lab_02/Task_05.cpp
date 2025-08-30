#include<iostream>
using namespace std;

void display(int **arr,int row,int col){
    cout<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void addMatrices(int **arr1, int **arr2,int row, int col){
    int** result = new int*[row];
    for(int i=0;i<row;i++){
        result[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    display(result,row,col);
    
}
void subtractMatrices(int **arr1, int **arr2,int row, int col){
    int** result = new int*[row];
    for(int i=0;i<row;i++){
        result[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result[i][j]=arr1[i][j]-arr2[i][j];
        }
    }
    display(result,row,col);
    
}

int main(){
    int row,col;
    cout<<"Number of Rows? ";
    cin>>row;
    cout<<"Number of Cols? ";
    cin>>col;

    int** arr1 = new int*[row];
    for(int i=0;i<row;i++){
        arr1[i]=new int[col];
    }
    cout<<"Enter Values in Matrix A:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr1[i][j];
        }
    }

    int** arr2 = new int*[row];
    for(int i=0;i<row;i++){
        arr2[i]=new int[col];
    }
    cout<<"Enter Values in Matrix B:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr2[i][j];
        }
    }

    cout<<"Result after Addition: ";
    addMatrices(arr1,arr2,row,col);
    cout<<"Result after Subtraction: ";
    subtractMatrices(arr1,arr2,row,col);
    
    for(int i=0;i<row;i++){
        delete[] arr1[i];
        delete[] arr2[i];
    }
    delete[] arr1;
    delete[] arr2;

}