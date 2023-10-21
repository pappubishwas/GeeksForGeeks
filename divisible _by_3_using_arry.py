#User function Template for python3

class Solution:
    def sumdigit(self,n):
        s=0
        while n>0:
            s+=n%10
            n//=10
        return s    
    def isPossible(self, N, arr):
        # code here
        s=0
        for i in range(0,N):
            s+=self.sumdigit(arr[i])
        return 1 if s%3==0 else 0    

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split()
        for i in range(N):
            arr[i] = int(arr[i])
        
        ob = Solution()
        print(ob.isPossible(N, arr))
# } Driver Code Ends