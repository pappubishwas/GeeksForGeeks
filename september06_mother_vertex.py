
class Solution:
    def dfs(self, v, adj, visited):
        visited[v] = True

        for u in adj[v]:
            if not visited[u]:
                self.dfs(u, adj, visited)

    def findMotherVertex(self, V, adj):
        visited = [False] * V
        last_visited_vertex = 0  # Initialize with the first vertex

        # Perform DFS on all vertices to find the last visited vertex.
        for i in range(V):
            if not visited[i]:
                self.dfs(i, adj, visited)
                last_visited_vertex = i

        # Reset visited array for the next DFS.
        visited = [False] * V

        # Perform DFS from the last visited vertex.
        self.dfs(last_visited_vertex, adj, visited)

        # Check if the last visited vertex is a mother vertex.
        for i in range(V):
            if not visited[i]:
                return -1  # No mother vertex found.

        return last_visited_vertex  # Return the mother vertex


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys 

sys.setrecursionlimit(10**6) 
if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		V, E = map(int, input().split())
		adj = [[] for i in range(V)]
		for _ in range(E):
			u, v = map(int, input().split())
			adj[u].append(v)
		obj = Solution()
		ans = obj.findMotherVertex(V, adj)
		print(ans)
# } Driver Code Ends