
from typing import List


class Solution:
    def sumOfPowers(self, a: int, b: int) -> int:
        v = [-1] * (b + 1)
        v[0] = 0
        v[1] = 1
        i = 2
        while i <= b:
            if v[i] == -1:
                x = i
                while x <= b:
                    v[x] = i
                    x += i
            i += 1
        
        ans = 0
        for i in range(a, b + 1):
            x = i
            while x > 1:
                ans += 1
                x //= v[x]
        
        return ans

#{ 
 # Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        a=int(input())
        b=int(input())
        
        obj = Solution()
        res = obj.sumOfPowers(a,b)
        
        print(res)
        

# } Driver Code Ends