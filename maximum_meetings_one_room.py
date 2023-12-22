from typing import List

class Meet:
    def __init__(self,a,b,c):
        self.start=a
        self.end=b
        self.index=c

class Solution:
    def maxMeetings(self, N : int, S : List[int], F : List[int]) -> List[int]:
        # code here
        times=[]
        
        for i in range(N):
            times.append(Meet(S[i],F[i],i+1))
        
        times.sort(key=lambda x: (x.end,x.index))
        
        ans=[]
        lastend=-1
        
        for i in range(N):
            if times[i].start>lastend:
                ans.append(times[i].index)
                lastend=times[i].end
        ans.sort()
        
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
        
        N = int(input())
        
        
        S=IntArray().Input(N)
        
        
        F=IntArray().Input(N)
        
        obj = Solution()
        res = obj.maxMeetings(N, S, F)
        
        IntArray().Print(res)
        

# } Driver Code Ends