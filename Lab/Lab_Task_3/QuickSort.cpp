/*
Lab 2: Quick Sort
Quick Sort is a divide-and-conquer algorithm that selects a pivot element, partitions the
array around the pivot, and recursively sorts the subarrays. Its average-case time
complexity is O(nlog⁡n). In this task, you have to write a program that will sort an array in
ascending order using a quick sort algorithm. You have to implement Quick Sort and
allow the user to select the pivot strategy:
1. First element as pivot.
2. Last element as pivot.
3. Middle element as pivot.
For each of the strategies, calculate the total time required to run the program using
clock() function in c and find out the most efficient element to be selected as pivot for
your input.
*/

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high, int pivot)
{
	int i = low;
	int j = low;
	while (i <= high)
	{
		if (arr[i] > pivot)
		{
			i++;
		}
		else
		{
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
	}
	return j - 1;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = arr[high];
		int pos = partition(arr, low, high, pivot);

		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
}

void quickSort1(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = arr[(low + high) / 2];
		int pos = partition(arr, low, high, pivot);

		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
}

void quickSort2(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = arr[low];
		int pos = partition(arr, low, high, pivot);

		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	clock_t before = clock();

	quickSort(arr, 0, n - 1);

	clock_t duration = clock() - before;
	cout << "Duration: " << (float)duration / CLOCKS_PER_SEC * 1000 << " mseconds";
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	before = clock();

	quickSort1(arr, 0, n - 1);

	duration = clock() - before;
	cout << "Duration: " << (float)duration / CLOCKS_PER_SEC * 1000 << " mseconds";
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	before = clock();

	quickSort2(arr, 0, n - 1);

	duration = clock() - before;
	cout << "Duration: " << (float)duration / CLOCKS_PER_SEC * 1000 << " mseconds";
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}