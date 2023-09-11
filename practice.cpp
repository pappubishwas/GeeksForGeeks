#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// Function to compress the input string
string tostring(int number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}

string pressString(const string &s)
{
    string com;
    int count = 1; // Initialize a count1
    for (int i = 0; i < s.length(); i++)
    {
        if (i + 1 < s.length() && s[i] == s[i + 1])
        { // jodi present character ti porer tar same hoy taile count increase
            count++;
        }
        else
        {
            com += tostring(count) + s[i]; // Add the count and character to the compressed string
            count = 1;
        }
    }

    return com; // Return the compressed string
}

int main()
{
    int t;
    cin >> t;     // test case
    cin.ignore(); // Consume the newline character

    while (t--)
    {
        string s;
        getline(cin, s);             // Read the input string
        string com = pressString(s); // function call
        cout << com << endl;         // Print the compressed string
    }
}