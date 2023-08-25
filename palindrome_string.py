# User function Template for python3
class Solution:
    def isPalindrome(self, S):
        # code here
        s = 0
        e = len(S)-1
        while s < e:
            if S[s] != S[e]:
                return 0
            s += 1
            e -= 1

        return 1


# {
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '_main_':
    T = int(input())
    for i in range(T):
        S = input()
        ob = Solution()
        answer = ob.isPalindrome(S)
        print(answer)

# } Driver Code Ends
