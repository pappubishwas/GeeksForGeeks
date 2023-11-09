#User function Template for python3

class Solution:
    def columnWithMaxZeros(self,a,n):
        # code here 
        cz,ind=0,-1
        for i in range(n):
            c=0
            for j in range(n):
                if a[j][i]==0:
                    c+=1
            if c==n:
                return i
            if c>cz:
                cz=c
                ind=i
        return ind        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = []
        for i in range(N):
            line = [int(x) for x in input().strip().split()]
            arr.append(line)
        ob=Solution()
        print(ob.columnWithMaxZeros(arr,N))


# } Driver Code Ends