// Recursive implementation of Binary Search

#include <iostream>
using namespace std;

// Recursive implementation of Binary Search
// arr[]: The array to search in
// key: The value to search for
// low: The starting index of the current search range
// high: The ending index of the current search range
int binarySearch(int arr[], int key, int low, int high)
{
    // Base case: If the search range is invalid, the key is not in the array
    if (low > high)
    {
        return -1; // Key not found
    }

    // Calculate the middle index to divide the array into halves
    int mid = low + (high - low) / 2;

    // Check if the middle element is the key
    if (key == arr[mid])
    {
        return mid; // Key found at index mid
    }
    // If the key is greater than the middle element, search in the right half
    else if (key > arr[mid])
    {
        return binarySearch(arr, key, mid + 1, high);
    }
    // If the key is smaller than the middle element, search in the left half
    else
    {
        return binarySearch(arr, key, low, mid - 1);
    }
}

int main()
{
    // The array must be sorted for binary search
    int arr[10] = {0, 1, 4, 6, 9, 10, 28, 32, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Input key to search
    int key;
    cout << "Enter a number for the key value: ";
    cin >> key;

    // Call binarySearch with indices 0 and size - 1
    int index = binarySearch(arr, key, 0, size - 1);

    // Check the result and print the appropriate message
    if (index != -1)
    {
        cout << "Found the value at index: " << index << endl; // Key found
    }
    else
    {
        cout << "Not found!" << endl; // Key not found
    }

    return 0;
}
