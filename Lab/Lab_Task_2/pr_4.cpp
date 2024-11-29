/*
During an intense battle, Captain America's shield takes several hits. Each impact is
measured and recorded in an array, where each number represents the strength of a hit.
To assess the shield's integrity, Captain needs to find the weakest and strongest hits
from the recorded data.
Your mission is to write a program that uses recursion to determine the minimum and
maximum values from the array of hits
*/

#include <iostream>
using namespace std;

void findMinMax(int arr[], int start, int end, int &minVal, int &maxVal)
{

    if (start == end)
    {
        if (arr[start] < minVal)
            minVal = arr[start];
        if (arr[start] > maxVal)
            maxVal = arr[start];
        return;
    }

    if (end == start + 1)
    {
        if (arr[start] < arr[end])
        {
            if (arr[start] < minVal)
                minVal = arr[start];
            if (arr[end] > maxVal)
                maxVal = arr[end];
        }
        else
        {
            if (arr[end] < minVal)
                minVal = arr[end];
            if (arr[start] > maxVal)
                maxVal = arr[start];
        }
        return;
    }

    int mid = (start + end) / 2;
    findMinMax(arr, start, mid, minVal, maxVal);
    findMinMax(arr, mid + 1, end, minVal, maxVal);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int minVal = INT_MAX, maxVal = INT_MIN;
    findMinMax(arr, 0, n - 1, minVal, maxVal);

    cout << "Min: " << minVal << endl;
    cout << "Max: " << maxVal << endl;

    return 0;
}
