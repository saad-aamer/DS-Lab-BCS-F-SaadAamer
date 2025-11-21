#include <iostream>
using namespace std;

struct runner {
    string name;
    int time;
};

void merge(runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    runner* L = new runner[n1];
    runner* R = new runner[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Runner arr[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    Runner runners[10];

    cout << "Enter names and finish times of 10 participants:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Runner " << i + 1 << " name: ";
        cin >> runners[i].name;
        cout << "Finish time (seconds): ";
        cin >> runners[i].time;
    }

    mergeSort(runners, 0, 9);

    cout << "\nTop 5 Fastest Runners:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << runners[i].name 
             << " - " << runners[i].time << " seconds\n";
    }

    return 0;
}
