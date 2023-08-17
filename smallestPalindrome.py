#User function Template for python3

class Solution:
    def generateNextPalindrome(self, num, n):
        ans = [0] * n
        if n == 1:
            ans[0] = num[0] + 1
            if ans[0] > 9:
                ans = [1, 1]
            return ans
        
        s, e, rem, k = 0, n - 1, 0, 0
        while s < e:
            if num[s] > num[e]:
                rem = 1
                ans[s] = num[s]
                ans[e] = num[s]
            elif num[s] == num[e]:
                ans[s] = num[s]
                ans[e] = num[s]
            else:
                rem = 1
                if e - 1 >= 0:
                    num[e - 1] += 1
                    k = e - 1
                ans[s] = num[s]
                ans[e] = num[s]
            if ans[s] > 9 or ans[e] > 9:
                rem = 1
                ans[s - 1] += 1
                ans[s] = 0
                ans[e] = 0
                ans[e + 1] += 1
            s += 1
            e -= 1
        
        if num[s] > 9 and s == e:
            rem = 1
            ans[s - 1] += 1
            ans[s + 1] += 1
            ans[s] = 0
        elif s == e:
            if k == s or rem == 1:
                ans[s] = num[s]
            else:
                ans[s] = num[s] + 1
            rem = 1
        
        if rem == 0:
            ans = [1] + [0] * (n - 1) + [1]
        
        s, e = 0, n - 1
        while s < e:
            if ans[s] > 9 or ans[e] > 9:
                rem = 1
                ans[s - 1] += 1
                ans[s] = 0
                ans[e] = 0
                ans[e + 1] += 1
                if s - 2 >= 0:
                    s = s - 2
                else:
                    s -= 1
                if e + 2 < n:
                    e = e + 2
                else:
                    e += 1
            s += 1
            e -= 1
        
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3



# Driver code 
if __name__ == "__main__": 		
    tc=int(input())
    while tc > 0:
        n=int(input())
        num=list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.generateNextPalindrome(num, n)
        for x in ans:
            print(x, end=" ")
        print()
        tc=tc-1
# } Driver Code Ends