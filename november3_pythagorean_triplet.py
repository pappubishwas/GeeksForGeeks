# #User function Template for python3
# class Solution:

# 	def checkTriplet(self,arr, n):
#     	# code here
class Solution:
    def checkTriplet(self, arr, n):
        if n < 3:
            return False
        
        arr.sort()
        for i in range(n):
            arr[i] = arr[i] * arr[i]
        
        for k in range(n - 1, 1, -1):
            if arr[k] == arr[k - 1]:
                continue
            i, j = 0, k - 1
            while i < j:
                if arr[i] + arr[j] == arr[k]:
                    return True
                elif arr[i] + arr[j] < arr[k]:
                    i += 1
                else:
                    j -= 1
        return False



#{ 
 # Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.checkTriplet(arr, n)
        if ans:
            print("Yes")
        else:
            print("No")
        tc -= 1

# } Driver Code Ends