#include<iostream>

void sort(int[], int);
void print(int[], int);

using namespace std;
int main() {
    int size = 10;
    int arr[size];
    
    cout << "Enter the elements:\n";

    for(int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Initial Array: ";
    print(arr, size);

    sort(arr, size);

    cout << "Final Array: ";
    print(arr, size);
}

void print(int arr[], int size) {
    cout << "{ " << arr[0];

    for(int i = 1; i < size; i++)
        cout << ", " << arr[i];
    
    cout << " }\n";
}

void sort(int arr[], int n) {
    int j, k;
    for (int i = 1; i < n; i++) {
        k = arr[i];
        for(j = i - 1; j >= 0 && k < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = k;
    }
}