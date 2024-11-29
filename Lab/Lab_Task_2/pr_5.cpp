/*
Task 5: Is this a Palindrome?
Write a recursive program to check if a given string is a palindrome or not (not case
sensitive, ignore whitespaces)
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(const string &str, int start, int end)
{
    if (start >= end)
        return true;

    if (isspace(str[start]))
    {
        return isPalindrome(str, start + 1, end);
    }

    if (isspace(str[end]))
    {
        return isPalindrome(str, start, end - 1);
    }

    if (tolower(str[start]) != tolower(str[end]))
        return false;

    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
    string str;
    getline(cin, str);

    if (isPalindrome(str, 0, str.length() - 1))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}
