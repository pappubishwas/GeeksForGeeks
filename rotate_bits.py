#User function Template for python3

class Solution:
    
    def rotate(self, n, d):
        # code here
        d=d%16
        return [self.leftRotate(n,d),self.rightRotate(n,d)]
    
    def leftRotate(self,x,d):  
        SHORT_SIZE=16
        return ((x<<d) | (x>>(SHORT_SIZE-d))) & 0xFFFF
        
    def rightRotate(self,x,d):
        SHORT_SIZE=16
        return ((x>>d)| (x<<(SHORT_SIZE-d))) & 0xFFFF

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, d = input().strip().split(" ")
        n, d = int(n), int(d)
        ob = Solution()
        ans = ob.rotate(n, d)
        print(ans[0])
        print(ans[1])
# } Driver Code Ends