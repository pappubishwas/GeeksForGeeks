//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
   // Check weather a number is prime or not
    bool checkPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    //finding the sum of digits of a number
    int digitsum(int j){
        int sum=0;
        while(j>0){
                sum+=j%10;
                j/=10;
        }
        return sum;
    }
    
    int smithNum(int n) {
        int sumDigit = 0, sumFactor = 0;
        if(checkPrime(n)) return false;
        sumDigit=digitsum(n);

        // Find prime factors of n and calculate their sum
        for (int i = 2; i <= n; i++) {
            int sum=digitsum(i);
            while (n % i == 0 && checkPrime(i)) {
                sumFactor+=sum;
                n/=i;
            }
        }

        // If n > 1, add its remaining prime factor
        if (n > 1 && checkPrime(n))
        {
                sumFactor+=digitsum(n);
        }

        return sumFactor == sumDigit;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends