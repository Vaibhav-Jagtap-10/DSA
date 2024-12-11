#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i, n is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;      // left = 2*i + 1
    int right = 2 * i + 2;     // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Main function to implement heap sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end (swap)
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Utility function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    // Taking input from the user
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];  // Declaring the array with the given size

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Unsorted array: ";
    printArray(arr, n);

    // Perform heap sort
    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
