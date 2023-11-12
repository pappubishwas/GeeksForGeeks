//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    long long minimumTime(int N, int NUM, vector<int> &time) {
        long long int l, r, t, temp;

        // Sort in ascending order
        sort(time.begin(), time.end());

        // Initialize l and r based on the time range
        l = 0;
        r = static_cast<long long>(NUM) * time[N - 1] + 1; // Adjust initialization
        t = LLONG_MAX;

        while (l < r) {
            long long int mid = (l + r) / 2;
            temp = 0;

            for (int i = 0; i < N; i++) {
                temp += (mid / time[i]);
            }

            if (temp >= NUM) {
                r = mid; // Adjust update to include mid
                t = min(t, mid);
            } else {
                l = mid + 1;
            }
        }

        return t;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int NUM;
        scanf("%d",&NUM);
        
        
        vector<int> time(N);
        Array::input(time,N);
        
        Solution obj;
        long long res = obj.minimumTime(N, NUM, time);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends