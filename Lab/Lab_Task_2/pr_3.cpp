/*
Task 3: Thor's Hammer Energy Amplification
Thor is preparing for his next battle against cosmic threats. His hammer, Mjölnir, can
amplify its energy output by harnessing the power of magical elements. These
elements are represented as an array of integers, and the energy amplification is the
product of all the element values.
Unfortunately, Thor's calculations were disrupted by Loki's tricks, and he now needs
your help to create a recursive program that computes the total energy amplification
from an array of magical elements.
Your task is to write a recursive function to find the product of all elements in the
array.
*/

#include <iostream>
using namespace std;

int product(int arr[], int n)
{
    if (n == 0)
    {
        return 1;
    }

    return arr[n - 1] * product(arr, n - 1);
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

    cout << product(arr, n);
}