#User function Template for python3

class Solution:
    def transitiveClosure(self, N, grid):
        n = N
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if i == j:
                        grid[i][j] = 1
                    if grid[i][j] == 0:
                        if grid[i][k] == 1 and grid[k][j] == 1:
                            grid[i][j] = 1

        return grid

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        graph = []
        for i in range(0,N):
            graph.append([int(j) for j in input().split()])
        ob = Solution()
        ans = ob.transitiveClosure(N, graph)
        for i in range(N):
            for j in range(N):
                print(ans[i][j], end = " ")
            print()
# } Driver Code Ends