#include <iostream>
using namespace std;

class Product {
public:
    string name;
    float price;
    string description;
    bool available;
};

int partition(Product arr[], int low, int high) {
    float pivot = arr[high].price;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            Product temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Product temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Product products[3];

    cout << "Enter details for 3 products:\n";

    for (int i = 0; i < 3; i++) {
        cout << "\nProduct " << i + 1 << " name: ";
        cin >> products[i].name;

        cout << "Price: ";
        cin >> products[i].price;

        cout << "Description: ";
        cin.ignore();
        getline(cin, products[i].description);

        cout << "Available (1 for yes, 0 for no): ";
        cin >> products[i].available;
    }

    quickSort(products, 0, 2);

    cout << "\nProducts sorted by price (ascending):\n";

    for (int i = 0; i < 3; i++) {
        cout << "\nProduct Name: " << products[i].name;
        cout << "\nPrice: " << products[i].price;
        cout << "\nDescription: " << products[i].description;
        cout << "\nAvailable: " << (products[i].available ? "Yes" : "No") << "\n";
    }

    return 0;
}
