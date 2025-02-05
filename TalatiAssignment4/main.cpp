#include <iostream>
using namespace std;


void heapify(int arr[], int n) {
    // Your code here
    // Build the heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        int largest = i;
        int current = i;
        while (true) {
            int left = 2 * current + 1;  // Left child
            int right = 2 * current + 2; // Right child
            if (left < n && arr[left] > arr[largest])
                largest = left;
            if (right < n && arr[right] > arr[largest])
                largest = right;
            if (largest == current)
                break;
            swap(arr[current], arr[largest]);
            current = largest;
        }
    }
}

// Main function to perform heap sort on the array
void heapSort(int arr[], int n) {
    // Step 1: Build a max-heap
    heapify(arr, n);
    // Step 2: Extract elements from the heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move the current root (largest) to the end of the array
        swap(arr[0], arr[i]);
        // Step 3: Down Heapify
        heapify(arr, i);
    }
}


// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test array
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    // Call the heapSort function
    heapSort(arr, n);

    cout << "Sorted array:\n";
    printArray(arr, n);

    return 0;
}