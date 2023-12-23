#User function Template for python3


from collections import defaultdict

class Solution:
    def countOccurence(self, arr, n, k):
        mp = defaultdict(int)
        for i in range(n):
            mp[arr[i]] += 1
        
        ans = 0
        for i in range(n):
            if mp[arr[i]] * k > n:
                ans += 1
                mp[arr[i]] = 0
        
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math



def main():
        T=int(input())
        while(T>0):
            
            N=int(input())

            A=list(map(int,input().split()))
            
            K=int(input())
            
            print(Solution().countOccurence(A, N, K))
            
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends