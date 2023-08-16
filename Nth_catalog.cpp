#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1000000007; // 1e9 + 7

    // Function to calculate factorial using modulo
    long long factorial(int n) {
        long long result = 1;
        for (int i = 1; i <= n; ++i) {
            result = (result * i) % mod;
        }
        return result;
    }

    int findCatalan(int n) {
        long long fact[2 * n + 1];
        fact[0] = 1;
        for (int i = 1; i <= 2 * n; ++i) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        long long num = fact[2 * n];
        long long den = (fact[n + 1] * fact[n]) % mod;

        long long result = (num * mod_inverse(den, mod)) % mod;

        return static_cast<int>(result);
    }

    long long mod_inverse(long long a, long long mod) {
        long long res = 1;
        long long base = a;
        long long exp = mod - 2;

        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        int res = obj.findCatalan(n);
        cout << res << "\n";
    }
    return 0;
}
