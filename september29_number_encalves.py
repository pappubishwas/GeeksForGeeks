#User function Template for python3

from typing import List

class Solution:
    def mark_boundary(self, grid, visited, k, d):
        n, m = len(grid), len(grid[0])
        visited[k][d] = True
        stack = [(k, d)]

        while stack:
            p = stack.pop()
            i, j = p[0], p[1]

            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

            for dir in directions:
                x, y = i + dir[0], j + dir[1]

                if 0 <= x < n and 0 <= y < m and grid[x][y] == 1 and not visited[x][y]:
                    visited[x][y] = True
                    stack.append((x, y))

    def numberOfEnclaves(self, grid):
        n, m = len(grid), len(grid[0])
        visited = [[False] * m for _ in range(n)]

        for i in range(m):
            if grid[0][i] == 1 and not visited[0][i]:
                self.mark_boundary(grid, visited, 0, i)
            if grid[n - 1][i] == 1 and not visited[n - 1][i]:
                self.mark_boundary(grid, visited, n - 1, i)

        for i in range(n):
            if grid[i][0] == 1 and not visited[i][0]:
                self.mark_boundary(grid, visited, i, 0)
            if grid[i][m - 1] == 1 and not visited[i][m - 1]:
                self.mark_boundary(grid, visited, i, m - 1)

        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and not visited[i][j]:
                    count += 1

        return count


#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == "__main__":
    for _ in range(int(input())):
        n, m = map(int,input().strip().split())
        grid = []
        for i in range(n):
            grid.append([int(i) for i in input().strip().split()])

        obj=Solution()
        print(obj.numberOfEnclaves(grid))
# } Driver Code Ends