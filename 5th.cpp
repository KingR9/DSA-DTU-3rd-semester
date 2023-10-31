#include<iostream>
using namespace std;

void insert(int arr[], int &size, int &capacity, int value) {
    if (size == capacity) {
        cout << "Overflow: The array is full and cannot accommodate new elements." << endl;
        return;
    }

    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = value;
    size++;
}

void del(int arr[], int &size, int &capacity) {
    if (size == 0) {
        cout << "Underflow: The array is empty and cannot delete elements." << endl;
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int capacity = size;

    // insert function
    cout << "Inserting 10 at the beginning..." << endl;
    insert(arr, size, capacity, 10);
    cout << "New array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // delete function
    cout << "Deleting the first element..." << endl;
    del(arr, size, capacity);
    cout << "New array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}