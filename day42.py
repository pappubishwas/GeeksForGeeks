#User function Template for python3

class Solution:
    def Count(self, matrix):
        n, m = len(matrix), len(matrix[0])
        total_count = 0
        
        for i in range(n):
            for j in range(m):
                count = 0
                
                if matrix[i][j] == 1:
                    if i - 1 >= 0 and matrix[i - 1][j] == 0:
                        count += 1
                    if i + 1 < n and matrix[i + 1][j] == 0:
                        count += 1
                    if j - 1 >= 0 and matrix[i][j - 1] == 0:
                        count += 1
                    if j + 1 < m and matrix[i][j + 1] == 0:
                        count += 1
                    if i - 1 >= 0 and j - 1 >= 0 and matrix[i - 1][j - 1] == 0:
                        count += 1
                    if i + 1 < n and j + 1 < m and matrix[i + 1][j + 1] == 0:
                        count += 1
                    if i + 1 < n and j - 1 >= 0 and matrix[i + 1][j - 1] == 0:
                        count += 1
                    if i - 1 >= 0 and j + 1 < m and matrix[i - 1][j + 1] == 0:
                        count += 1
                
                if count != 0 and count % 2 == 0:
                    total_count += 1
        
        return total_count


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n, m = input().split()
		n = int(n); m = int(m);
		matrix = []
		for _ in range(n):
			matrix.append(list(map(int,input().split())))
		ob = Solution()
		ans = ob.Count(matrix)
		print(ans)

# } Driver Code Ends