#include<iostream>
using namespace std;

void occupySeat(int** arr, int row, int col) {
	arr[row][col] = 1;
}
void display(int** arr,int rows,int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout<<endl;
}
int main() {
	int rows, cols;
	cout << "Number of Rows ? ";
	cin >> rows;
	cout << "Number of Columns ? ";
	cin >> cols;
	int** arr = new int*[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = 0;
		}
	}
	cout << "Originally Declared Array: " << endl;
	display(arr, rows, cols);
	cout << "Select Seat Row :";
	int r, c;
	cin >> r;
	cout << "Select Seat Column :";
	cin >> c;
	occupySeat(arr, r, c);
	cout << "Updated Array: " << endl;
	display(arr, rows, cols);
	for (int i = 0; i < rows; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}