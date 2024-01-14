#User function Template for python3

# class Solution:
#     def repeatedRows(self, arr, m ,n):
#         #code here
from typing import List

class Solution:
    def repeatedRows(self, matrix: List[List[int]], M: int, N: int) -> List[int]:
        mp = {}
        for i in range(len(matrix)):
            t = tuple(matrix[i])
            if t in mp:
                mp[t].append(i)
            else:
                mp[t] = [i]
        
        ans = []
        for indices in mp.values():
            sorted(indices)
            if len(indices) > 1:
                ans.extend(indices[1:])
        
        return sorted(ans)
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, m = list(map(int, input().strip().split()))
        
        arr = []
        for i in range(n):
            nums = list(map(int, input().strip().split()))
            arr.append(nums)
        ob = Solution()
        ans = ob.repeatedRows(arr, n, m)
        
        for x in ans:
            print(x, end=" ")
            
        print()
        tc -= 1

# } Driver Code Ends