#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s0;
    string s1("Hello");
    string s2 = "Hello World";
    string s3(s2);  // copy constructor
    string s4 = s3; // assigning a string to another string

    char a[] = {'a', 'b', 'c', '\0'};
    string s5(a);
    cout << s0 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    if (s0.empty())
    {
        cout << "S0 is an Empty string" << endl;
    }

    // Append
    s0.append("I Love C++");
    cout << s0 << endl;
    // we can also use the += operator as well

    // Remove everything
    cout << s0.size() << endl;
    s0.clear();
    cout << s0.size() << endl;

    // compare two strings
    s0 = "Apple";
    s1 = "Mango";
    cout << s0.compare(s1) << endl; // returns an integer ==0 equal , >0 or <0
    // if ans is <0 then the string s0 is lexicogrpahically smaller than s1
    // if ans is >0 then the string s0 is lexicographicallly greater than s1

    // overloaded operators
    if (s0 > s1)
    {
        cout << "Mango is less" << endl;
    }
    else
    {
        cout << "Mango is more" << endl;
    }

    // Find substrings
    string s = "I want to have apple juice";
    // if we need to find the index in which apple comes in the above string
    int idx = s.find("apple"); // returns the index where the word starts
    cout << idx << endl;

    // Remove a word from the string
    string word = "apple";
    int len = word.size();
    cout << s << endl;
    s.erase(idx, len + 1); // 1st argument is the idx and len will be the no of characters we want to delete from idx
    cout << s << endl;

    // iterate over all the char of the strings
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] << ":";
    }
    cout << endl;
    // iterator
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << ",";
    }
    cout << endl;
    // For each loop
    for (auto c : s)
    {
        cout << c << "->";
    }
    cout << endl;
    return 0;
}