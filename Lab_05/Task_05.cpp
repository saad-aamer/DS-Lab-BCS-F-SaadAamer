#include<iostream>
using namespace std;

#define n 9

void print(int arr[][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

bool isSafe(int arr[][n], int row, int col, int num){
    for(int j=0;j<n;j++){
        if(arr[row][j]==num){
            return false;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i][col]==num){
            return false;
        }
    }
    int currRow= (row/3)*3;
    int currCol= (col/3)*3;
    for(int i=currRow;i<=currRow+2;i++){
        for(int j=currCol;j<=currCol+2;j++){
            if(arr[i][j]==num){
                return false;
            }
        }
    }
    return true;
}

bool helper(int arr[][n], int row, int col){
    if(row==9){
        return true;
    }
    int nxtRow=row;
    int nxtCol=col+1;
    if(nxtCol==9){
        nxtRow=row+1;
        nxtCol=0;
    }
    if(arr[row][col]!=0){
        return helper(arr,nxtRow,nxtCol);
    }
    for(int num=1; num<=9; num++){
        if(isSafe(arr,row,col,num)){
            arr[row][col]=num;
            if(helper(arr,nxtRow,nxtCol)){
                return true;
            }
            arr[row][col]=0;
        }
    }
    return false;
}

bool sudokuSolver(int arr[][n]){
    return helper(arr,0,0);
}

int main() {
    int grid[n][n] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout<<"Original Sudoku Grid:"<<endl;
    print(grid);

    if(sudokuSolver(grid)){
        cout<<"\nSolved Sudoku Grid:"<<endl;
        print(grid);
    }
    else{
        cout<<"Can't Solve!"<<endl;
    }

    return 0;
}
