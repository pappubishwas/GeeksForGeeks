#User function Template for python3

from typing import List
 
from collections import deque

class Solution:
    def minimumMultiplications(self, arr, start, end):
        if start == end:
            return 0
        
        vis = [0] * 1000005
        q = deque()
        q.append((start, 0))
        vis[start] = 1
        
        while q:
            x, dist = q.popleft()
            
            for i in range(len(arr)):
                new_node = (arr[i] * x) % 100000
                
                if new_node == end:
                    return dist + 1
                
                if not vis[new_node]:
                    q.append((new_node, dist + 1))
                    vis[new_node] = 1
        
        return -1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    for _ in range(int(input())):
        n = int(input())
        arr = [int(x) for x in input().strip().split()]
        start, end = list(map(int,input().split()))
        obj=Solution()
        print(obj.minimumMultiplications(arr, start, end))
# } Driver Code Ends