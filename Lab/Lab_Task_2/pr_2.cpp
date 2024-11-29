/*
Task 2: Help Iron Man Decode the Binary Arc Reactor Core
Tony Stark, the genius billionaire inventor, is working on a secret upgrade for his Iron
Man suit. The Arc Reactor at the heart of his suit has a new feature—it requires all
numeric inputs to be converted into binary to optimize energy flow. Unfortunately,
J.A.R.V.I.S. is busy analyzing alien technology, and Tony needs your help to write a
program that converts numbers from decimal to binary.
Your Task is “Given a decimal number as input, we need to write a program to convert the given
decimal number into an equivalent binary number. “
*/

#include <iostream>
using namespace std;

void decimalToBinary(int n)
{
    if (n == 0)
    {
        return;
    }

    decimalToBinary(n / 2);
    cout << n % 2;
}

int main()
{
    int n;
    cin >> n;

    decimalToBinary(n);
}