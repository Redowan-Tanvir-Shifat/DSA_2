#include <iostream>
using namespace std;

int recursion(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * recursion(n - 1);
}

int main()
{
    int n;
    n = 5;
    cout << recursion(n);
}