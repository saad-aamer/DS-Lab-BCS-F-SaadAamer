#include <iostream>
using namespace std;

#define MAX_SIZE 100
#define MAX_PAIRS (MAX_SIZE * (MAX_SIZE - 1) / 2)

struct SumPair {
    int sum;
    int x;
    int y;
};

void findEqualSumPairs(int arr[], int n) {
    SumPair pairs[MAX_PAIRS];
    int pairCount = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int currentSum = arr[i] + arr[j];

            
            for (int k = 0; k < pairCount; k++) {
                if (pairs[k].sum == currentSum) {
                    int a = pairs[k].x;
                    int b = pairs[k].y;
                    if (a != arr[i] && a != arr[j] && b != arr[i] && b != arr[j]) {
                        cout << "(" << a << ", " << b << ") and "
                             << "(" << arr[i] << ", " << arr[j] << ")" << endl;
                        return;
                    }
                }
            }

            
            pairs[pairCount].sum = currentSum;
            pairs[pairCount].x = arr[i];
            pairs[pairCount].y = arr[j];
            pairCount++;
        }
    }

    cout << "No pairs found" << endl;
}

int main() {
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    findEqualSumPairs(arr1, n1); 
    int arr2[] = {3, 4, 7, 1, 12, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    findEqualSumPairs(arr2, n2); 
    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    findEqualSumPairs(arr3, n3); 

    return 0;
}
