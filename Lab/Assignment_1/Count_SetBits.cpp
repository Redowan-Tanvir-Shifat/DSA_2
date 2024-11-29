// Count Set-bits of a number

#include <iostream>
using namespace std;

// Function to count the number of set bits (1s) in the binary representation of a number
int countSetBits(int n)
{
    // Base case: If the number becomes 0, there are no more set bits
    if (n == 0)
    {
        return 0; // 0 has no set bits
    }

    // Recursive case:
    // (n % 2) checks whether the last bit is 1 (set bit). If it is, it adds 1 to the count.
    // countSetBits(n / 2) recursively counts the set bits in the rest of the number.
    return (n % 2) + countSetBits(n / 2);
}

int main()
{
    // Declare an integer variable to store user input
    int n;

    // Imput a number
    cout << "Enter a number: ";
    cin >> n;

    // Call the recursive function to count set bits and display the result
    cout << "Set-bits of the number: " << countSetBits(n) << endl;

    return 0;
}
