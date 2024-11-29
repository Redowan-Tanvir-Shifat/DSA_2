/*
Task 6: Finding clues among consonants!
Loki has left a secret message encoded in a string. He has hidden its true meaning
behind the consonants in the message. Thor has discovered that the total number of
consonants in the string holds the key to unlocking its mystery. Your task is, Given a
string, find the total number of consonants (vowels: a,e,i,o,u)
NB: Try to find the total number of unique consonants. That means pass the array by
removing the duplicates first!
*/

#include <iostream>
#include <cctype>
using namespace std;

int findConsonants(const string &str, int i)
{

    if (i == str.length())
    {
        return 0;
    }

    char ch = tolower(str[i]);
    if (isalpha(ch) && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
    {

        return 1 + findConsonants(str, i + 1);
    }

    return findConsonants(str, i + 1);
}

int main()
{
    string str;
    getline(cin, str);

    int cnt = findConsonants(str, 0);
    cout << cnt << endl;

    return 0;
}
