#User function Template for python3


#Function to modify the matrix such that if a matrix cell matrix[i][j]
#is 1 then all the cells in its ith row and jth column will become 1.

class Solution:
    def makeOne(self, matrix, k, d, n, m):
        for i in range(m):
            matrix[k][i] = 1
        for i in range(n):
            matrix[i][d] = 1

def booleanMatrix(matrix):
    ans = []
    n = len(matrix)
    m = len(matrix[0])
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1:
                ans.append((i, j))

    for p in ans:
        Solution().makeOne(matrix, p[0], p[1], n, m)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        r,c = map(int, input().strip().split())
        matrix = []
        for i in range(r):
            line = [int(x) for x in input().strip().split()]
            matrix.append(line)
        booleanMatrix(matrix)
        for i in range(r):
            for j in range(c):
                print(matrix[i][j], end=' ')
            print()


# } Driver Code Ends