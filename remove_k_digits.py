#User function Template for python3

class Solution:

    def removeKdigits(self, S, K):
        # code here
        n=len(S)
        if K==n:
            return "0"
        
        stack=[]
        for digit in S:
            while stack and K>0 and stack[-1]>digit:
                stack.pop()
                K-=1
            stack.append(digit)
        while K>0:
            stack.pop()
            K-=1
        ans=""
        while stack:
            ans+=stack.pop()
        ans=ans[::-1]
        startIdx=len(ans)-1
        for i in range(len(ans)-1):
            if ans[i]!='0':
                startIdx=i
                break
        ans=ans[startIdx:]
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        S = input()
        K = int(input())

        obj = Solution()

        ans = obj.removeKdigits(S, K)

        print(ans)


# } Driver Code Ends