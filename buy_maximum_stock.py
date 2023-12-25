

from typing import List
import heapq

class Solution:
    def buyMaximumProducts(self, n : int, k : int, price : List[int]) -> int:
        # code here
        prices_with_indices=[(price[i],i+1) for i in range(n)]
        heapq.heapify(prices_with_indices)
        
        count=0
        
        while prices_with_indices:
            t1,t2=heapq.heappop(prices_with_indices)
            #t1=t1
            
            if k>=t1:
                if k>= t1*t2:
                    count+=t2
                    k-=t1*t2
                else:
                    count+=k//t1
                    k-=(k//t1)*t1
            else:
                break
        return count    
        



        


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
        
        n,k = map(int,input().strip().split())
        
        price=IntArray().Input(n)
        
        obj = Solution()
        res = obj.buyMaximumProducts(n, k, price)
        
        print(res)
        

# } Driver Code Ends