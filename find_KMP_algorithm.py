#User function Template for python3

# class Solution:
#     def search(self, pat, txt):
#         # code here
class Solution:
    def search(self, pat, txt):
        m = len(pat)
        n = len(txt)
        lps = [0] * m
        len1 = 0
        i = 1

        while i < m:
            if pat[i] == pat[len1]:
                len1 += 1
                lps[i] = len1
                i += 1
            else:
                if len1 != 0:
                    len1 = lps[len1 - 1]
                else:
                    lps[i] = 0
                    i += 1
        
        ans = []
        i = 0
        j = 0
        while i < n:
            if pat[j] == txt[i]:
                i += 1
                j += 1
            else:
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1
            if j == m:
                ans.append(i - j+1)
                j = lps[j - 1]

        if not ans:
            return [-1]
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        patt = input().strip()
        ob = Solution()
        ans = ob.search(patt, s)
        if len(ans)==0:
            print(-1,end="")
        for value in ans:
            print(value,end = ' ')
        print()
# } Driver Code Ends