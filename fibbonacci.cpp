//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
void multiply(int F[2][2], int M[2][2])
{
    int mod=1000000007;
// 	int x = (F[0][0] * M[0][0] + F[0][1] * M[1][0]);
// 	int y = (F[0][0] * M[0][1] + F[0][1] * M[1][1]);
// 	int z = (F[1][0] * M[0][0] + F[1][1] * M[1][0]);
// 	int w = (F[1][0] * M[0][1] + F[1][1] * M[1][1]);
	int x = ((F[0][0] * M[0][0])%mod + (F[0][1] * M[1][0])%mod)%mod;
	int y = ((F[0][0] * M[0][1])%mod + (F[0][1] * M[1][1])%mod)%mod;
	int z = ((F[1][0] * M[0][0])%mod + (F[1][1] * M[1][0])%mod)%mod;
	int w = ((F[1][0] * M[0][1])%mod + (F[1][1] * M[1][1])%mod)%mod;

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}
void power(int F[2][2], int n)
{
	if (n == 0 || n == 1)
		return;
	int M[2][2] = { { 1, 1 }, { 1, 0 } };

	power(F, n / 2);
	multiply(F, F);

	if (n % 2 != 0)
		multiply(F, M);
}

// Function that returns nth Fibonacci number
int nthFibonacci(int n)
{
    
    int mod=1000000007;
	int F[2][2] = { { 1, 1 }, { 1, 0 } };
	if (n == 0)
		return 0;
	power(F, n - 1);

	return F[0][0];
}

// Optimized version of power() in method 4



};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends