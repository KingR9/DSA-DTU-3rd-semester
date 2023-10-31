#include<iostream>
using namespace std;

void insert(int arr[], int &n, int x) {
    int new_arr[n+1];

    for (int i = 0; i < n; i++) {
        new_arr[i+1] = arr[i];
    }

    new_arr[0] = x;

    for (int i = 0; i <= n; i++) {
        arr[i] = new_arr[i];
    }

    n++;
}

void deleteAtBeginning(int arr[], int &n) {
    if (n == 0) {
        cout << "Array is empty" << endl;
        return;
    }

    for (int i = 0; i < n-1; i++) {
        arr[i] = arr[i+1];
    }

    n--;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Insert 10 at the beginning of the array
    insert(arr, n, 10);

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    deleteAtBeginning(arr, n);

    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}