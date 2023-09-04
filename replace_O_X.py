#User function Template for python3

class Solution:
    def floodFillUtil(self, mat, x, y, prevV, newV, M, N):
        if x < 0 or x >= M or y < 0 or y >= N:
            return
        if mat[x][y] != prevV:
            return
        
        mat[x][y] = newV
        
        self.floodFillUtil(mat, x+1, y, prevV, newV, M, N)
        self.floodFillUtil(mat, x-1, y, prevV, newV, M, N)
        self.floodFillUtil(mat, x, y+1, prevV, newV, M, N)
        self.floodFillUtil(mat, x, y-1, prevV, newV, M, N)
    
    def fill(self, M, N, mat):
        for i in range(M):
            for j in range(N):
                if mat[i][j] == 'O':
                    mat[i][j] = '-'
        
        for i in range(M):
            if mat[i][0] == '-':
                self.floodFillUtil(mat, i, 0, '-', 'O', M, N)
            if mat[i][N-1] == '-':
                self.floodFillUtil(mat, i, N-1, '-', 'O', M, N)
        
        for i in range(N):
            if mat[0][i] == '-':
                self.floodFillUtil(mat, 0, i, '-', 'O', M, N)
            if mat[M-1][i] == '-':
                self.floodFillUtil(mat, M-1, i, '-', 'O', M, N)
        
        for i in range(M):
            for j in range(N):
                if mat[i][j] == '-':
                    mat[i][j] = 'X'
        
        return mat

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, m = [int(x) for x in input().split()]
        mat = []
        for i in range(n):
            s = list(map(str,input().split()))
            mat.append(s)
        
        ob = Solution()
        ans = ob.fill(n, m, mat)
        for i in range(n):
            for j in range(m):
                print(ans[i][j], end = " ")
            print()
# } Driver Code Ends