#User function Template for python3

class Solution:
    def findMinOpeartion(self, matrix, n):
        max_sum = 0
        count = 0
        row = []
        
        for i in range(n):
            sum_row = 0
            sum_col = 0
            for j in range(n):
                sum_row += matrix[i][j]
                sum_col += matrix[j][i]
            row.append(sum_col)
            max_sum = max(max_sum, sum_col, sum_row)
        
        for i in range(n):
            count += abs(max_sum - row[i])
        
        return count



#{ 
 # Driver Code Starts

#Initial Template for Python 3

for _ in range(int(input())):
    n = int(input())
    matrix = [list(map(int,input().split())) for _ in range(n)]
    ob = Solution()
    print(ob.findMinOpeartion(matrix, n))
# } Driver Code Ends





# import numpy as np

# class Solution:
#     def findMinOpeartion(self, matrix, n):
#         matrix = np.array(matrix)
#         row_sums = np.sum(matrix, axis=1)
#         col_sums = np.sum(matrix, axis=0)
        
#         total_sum = np.sum(matrix)
#         max_sum = max(np.max(row_sums), np.max(col_sums))
        
#         count = np.sum(np.abs(max_sum - row_sums))
        
#         return count

# # Example usage
# matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
# n = 3
# sol = Solution()
# result = sol.findMinOpeartion(matrix, n)
# print(result)
