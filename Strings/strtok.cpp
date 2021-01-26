#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
// we can use this function to break the strings into a list of tokens
// char *strtok(char *s , char *delimiters) it returns the char ptr of the first element and then for the subsequent element we will use the below 2 methods
// returns a token on each subsequent call
// on the first call function should be passed with string argument for 's'
// on subsequent calls we should pass the string argument as null
int main()
{
    char s[100] = "Today is a rainy day";
    char *ptr = strtok(s, " ");
    cout << ptr << endl;
    while (ptr != NULL)
    {
        ptr = strtok(NULL, " ");
        cout << ptr << endl;
    }

    return 0;
}