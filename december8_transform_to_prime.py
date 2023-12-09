#User function Template for python3



from math import sqrt

class Solution:
    def minNumber(self, arr, n):
        sumall = sum(arr)
        prime = sumall
        if sumall == 1:
            return 1
        
        while True:
            flag = True
            for i in range(2, int(sqrt(prime)) + 1):
                if prime % i == 0:
                    flag = False
                    break
            if flag:
                return prime - sumall
            
            prime += 1  

        return -1




#{ 
 # Driver Code Starts
#Initial Template for Python 3


t=int(input())
for _ in range(0,t):
    n=int(input())
 #    l=list(map(int,input().split()))
 #    n=l[0]
 #    m=l[1]
    a=list(map(int,input().split()))
   # k = int(input())
  #  b = list(map(int, input().split()))
    ob = Solution()
    ans=ob.minNumber(a,n)
    print(ans)

# } Driver Code Ends