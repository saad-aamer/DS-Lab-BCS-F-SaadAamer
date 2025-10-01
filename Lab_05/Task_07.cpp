#include <iostream>
using namespace std;

#define MAX 20

void printSolution(int board[MAX][MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[MAX][MAX], int row, int col, int N) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;
    return true;
}

void solveNQueensUtil(int board[MAX][MAX], int row, int N, int &solutionCount) {
    if (row == N) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":\n";
        printSolution(board, N);
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            solveNQueensUtil(board, row + 1, N, solutionCount);
            board[row][col] = 0;
        }
    }
}

void solveNQueens(int board[MAX][MAX], int N) {
    int solutionCount = 0;
    solveNQueensUtil(board, 0, N, solutionCount);
    if (solutionCount == 0)
        cout << "No solutions exist for N = " << N << endl;
    else
        cout << "Total solutions for N = " << N << ": " << solutionCount << endl;
}

int main() {
    int N;
    cout << "Enter N for N-Queens: ";
    cin >> N;

    int board[MAX][MAX] = {0}; 
    solveNQueens(board, N);

    return 0;
}
