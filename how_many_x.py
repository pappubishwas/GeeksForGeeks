#User function Template for python3

class Solution:    
    def countX(self,L,R,X):
        #code here
        L+=1
        res=0
        while L<R:
            t=0
            p=L
            while p>0:
                if p%10==X:
                    t+=1
                p//=10
            L+=1
            res+=t
        return res    



#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        L,R,X=map(int,input().strip().split(" "))
        ob=Solution()
        ans=ob.countX(L,R,X)
        print(ans) 
# } Driver Code Ends