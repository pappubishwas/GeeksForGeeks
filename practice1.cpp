#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string s = "Hello world";
    int t = s.find("l");
    cout << t <<" "<<s.find("l",t+2);
}