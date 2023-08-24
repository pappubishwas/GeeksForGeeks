//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete below function */
    string multiplyStrings(string num1, string num2)
    {
        // Your code here
        int col, row, i, k, j, tm, flag = 0;
        if (num1[0] == '-' && num2[0] == '-')
        {
            num1.erase(num1.begin());
            num2.erase(num2.begin());
        }
        else if (num1[0] == '-')
        {
            flag = 1;
            num1.erase(num1.begin());
        }
        else if (num2[0] == '-')
        {
            flag = 1;
            num2.erase(num2.begin());
        }

        col = num1.length();
        row = num2.length();
        vector<int> v1;
        vector<int> v2;
        for (i = 0; i < col; i++)
        {
            tm = (num1[i] - 48);
            v1.push_back(tm);
        }
        for (i = 0; i < row; i++)
        {
            tm = (num2[i] - 48);
            v2.push_back(tm);
        }
        std::vector<std::vector<int>> mul(row, std::vector<int>(col + row, 0));

        i = row - 1;
        tm = col + row - 1;

        int t = 0, temp;
        while (i >= 0)
        {
            j = col - 1;
            k = tm;
            temp = 0;
            while (j >= 0)
            {
                mul[t][k] = v2[i] * v1[j] + temp;
                if (mul[t][k] > 9)
                {
                    temp = mul[t][k];
                    mul[t][k] = mul[t][k] % 10;
                    temp = temp / 10;
                }
                else
                    temp = 0;
                k--;
                j--;
            }
            if (temp > 0)
                mul[t][k] = temp;
            i--;
            tm--;
            t++;
        }

        i = row + col - 1;
        tm = col + row - 1;

        int sum = 0;
        string st;
        while (i >= 0)
        {
            j = 0;
            while (j < row)
            {
                sum += mul[j][i];
                j++;
            }
            if (sum > 9)
            {
                int mod = sum % 10;
                string s = to_string(mod);
                st = s + st;
                sum = sum / 10;
            }
            else
            {
                string s = to_string(sum);
                st = s + st;
                sum = 0;
            }
            i--;
        }

        while (st[0] == '0' && st.length() > 1)
            st.erase(0, 1);

        if (flag == 1)
            st = "-" + st;

        return st;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;
    }
}
// } Driver Code Ends