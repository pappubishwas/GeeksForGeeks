#User function Template for python3

class Solution:
    def smallestSubstring(self, S):
        one, zero, two = -1, -1, -1
        ans = float('inf')

        for i in range(len(S)):
            if S[i] == '0':
                zero = i
            elif S[i] == '1':
                one = i
            else:
                two = i
            
            if one != -1 and two != -1 and zero != -1:
                mn = min(one, two, zero)
                mx = max(one, two, zero)
                ans = min(ans, (mx - mn + 1))
        
        return -1 if ans == float('inf') else ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	t=int(input())
	for i in range(t):
		S = input()
		ob = Solution()
		ans = ob.smallestSubstring(S)
		
		print(ans)



# } Driver Code Ends