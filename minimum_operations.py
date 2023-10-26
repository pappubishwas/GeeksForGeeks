#User function Template for python3

class Solution:
    def minOperation(self, n):
        # code here 
        count=0
        while n>1:
            if n%2==1:
                count+=1
            count+=1
            n//=2
        
        return count+1    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        n = int(input())
        ob = Solution()
        print(ob.minOperation(n))
# } Driver Code Ends