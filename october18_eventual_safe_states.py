#User function Template for python3

from typing import List
from collections import deque
class Solution:    
    def eventualSafeNodes(self, V : int, adj : List[List[int]]) -> List[int]:
        # code here
        ans=[]
        arr=[[] for _ in range(V)]
        indegree=[0]*V
        for i in range(V):
            for it in adj[i]:
                arr[it].append(i)
                if indegree[i]==0:
                    indegree[i]=1
                else:
                    indegree[i]+=1
        q=deque()
        for i in range(V):
            if indegree[i]==0:
                q.append(i)
        
        while q:
            node=q.popleft()
            ans.append(node)
            for it in arr[node]:
                indegree[it]-=1
                if indegree[it]==0:
                    q.append(it)
        ans.sort()
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    T = int(input())
    for t in range(T):
        
        V, E = map(int, input().strip().split())
        adj = [[] for i in range(V)]
        for i in range(E):
            u, v = map(int, input().strip().split())
            adj[u].append(v)
        obj = Solution()
        ans = obj.eventualSafeNodes(V, adj)
        for nodes in ans:
            print(nodes, end = ' ')
        print()
            


# } Driver Code Ends