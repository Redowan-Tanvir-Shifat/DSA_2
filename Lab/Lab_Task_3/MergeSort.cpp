/*
Lab 1: Merge Sort
Merge Sort is a divide-and-conquer algorithm that splits the array into halves, recursively
sorts them, and then merges the sorted halves. It ensures O(nlog⁡n) time complexity. In
this task, you have to write a program that takes a number n, which is followed by a
variable p that includes the size of the array and the array itself, and the output of the
program is to sort each of the arrays in an ascending order.
*/

#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int arr1[n1];
    int arr2[n2];

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int s;
        cin >> s;
        int arr[s];

        for (int i = 0; i < s; i++)
        {
            cin >> arr[i];
        }

        mergeSort(arr, 0, s - 1);

        for (int i = 0; i < s; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // int arr[] = {70, 20, 30, 50, 60, 10, 40};
    // int size = sizeof(arr) / sizeof(arr[0]);

    // mergeSort(arr, 0, size - 1);

    // for(int i = 0; i < size; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    return 0;
}
