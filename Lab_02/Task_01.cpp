#include<iostream>
using namespace std;

void updateValue(int* arr, int position, int value) {
	(arr[position]) = value;
}
void display(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int* arr;
	int size;
	cout << "Enter Size of Array: ";
	cin >> size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		*(arr + i) = 0;
	}
	cout << "Originally Declared Array: " << endl;
	display(arr, size);
	int idx,value;
	cout << "Update at Index :";
	cin >> idx;
	cout << "Update Value :";
	cin >> value;
	updateValue(arr, idx, value);
	cout << "Updated Array: " << endl;
	display(arr, size);
	cout << endl;

	delete[] arr;
}