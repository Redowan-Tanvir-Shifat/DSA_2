// Find Sub array sum

#include <iostream>
#include <vector>
#include <climits>

// Structure to store the result of the subarray
struct Subarray
{
    int low;  // Starting index of the subarray
    int high; // Ending index of the subarray
    int sum;  // Sum of elements in the subarray
};

// Function to find the maximum crossing subarray
// This function considers subarrays that include elements from both left and right halves of the array
Subarray findMaxCrossingSubarray(const std::vector<int> &A, int low, int mid, int high)
{
    // Step 1: Initialize variables to find the maximum sum in the left part
    int leftSum = INT_MIN; // Store the maximum sum of the left part
    int sum = 0;           // Temporary sum variable
    int maxLeft = mid;     // Store the index where the left maximum sum starts

    // Step 2: Traverse from the middle to the leftmost element
    for (int i = mid; i >= low; --i)
    {
        sum += A[i]; // Add the current element to the sum
        if (sum > leftSum)
        {
            leftSum = sum; // Update the maximum sum
            maxLeft = i;   // Update the starting index
        }
    }

    // Step 3: Initialize variables to find the maximum sum in the right part
    int rightSum = INT_MIN; // Store the maximum sum of the right part
    sum = 0;                // Reset the temporary sum variable
    int maxRight = mid + 1; // Store the index where the right maximum sum ends

    // Step 4: Traverse from the middle+1 to the rightmost element
    for (int j = mid + 1; j <= high; ++j)
    {
        sum += A[j]; // Add the current element to the sum
        if (sum > rightSum)
        {
            rightSum = sum; // Update the maximum sum
            maxRight = j;   // Update the ending index
        }
    }

    // Step 5: Combine the left and right sums to get the crossing subarray sum
    return {maxLeft, maxRight, leftSum + rightSum};
}

// Function to find the maximum subarray
// This uses the divide-and-conquer approach
Subarray findMaximumSubarray(const std::vector<int> &A, int low, int high)
{
    // Step 1: Base case - if there is only one element in the array
    if (low == high)
    {
        return {low, high, A[low]}; // A subarray with one element has the sum equal to that element
    }
    else
    {
        // Step 2: Divide the array into two halves
        int mid = (low + high) / 2; // Find the middle index

        // Step 3: Recursively find the maximum subarray in the left half
        Subarray leftSubarray = findMaximumSubarray(A, low, mid);

        // Step 4: Recursively find the maximum subarray in the right half
        Subarray rightSubarray = findMaximumSubarray(A, mid + 1, high);

        // Step 5: Find the maximum subarray that crosses the middle
        Subarray crossSubarray = findMaxCrossingSubarray(A, low, mid, high);

        // Step 6: Return the subarray with the maximum sum among the three
        if (leftSubarray.sum >= rightSubarray.sum && leftSubarray.sum >= crossSubarray.sum)
        {
            return leftSubarray; // Left subarray has the maximum sum
        }
        else if (rightSubarray.sum >= leftSubarray.sum && rightSubarray.sum >= crossSubarray.sum)
        {
            return rightSubarray; // Right subarray has the maximum sum
        }
        else
        {
            return crossSubarray; // Crossing subarray has the maximum sum
        }
    }
}

int main()
{
    // Step 1: Define an example array
    // This array contains both positive and negative numbers
    std::vector<int> A = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7};

    // Step 2: Call the function to find the maximum subarray
    // Pass the array, starting index (0), and ending index (size - 1)
    Subarray result = findMaximumSubarray(A, 0, A.size() - 1);

    // Step 3: Print the result
    // Display the indices of the maximum subarray and its sum
    std::cout << "Maximum Subarray: Index: " << result.low << " to " << result.high << "\n";
    std::cout << "Maximum Sum: " << result.sum << "\n";

    return 0;
}
