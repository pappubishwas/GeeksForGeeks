#User function Template for python3

class Solution:
    def upto(self, s: str, k: int) -> int:
        l, r, cnt, ans = 0, 0, 0, 0
        mp = [0] * 26

        while r < len(s):
            mp[ord(s[r]) - ord('a')] += 1
            if mp[ord(s[r]) - ord('a')] == 1:
                cnt += 1

            while cnt > k:
                mp[ord(s[l]) - ord('a')] -= 1
                if mp[ord(s[l]) - ord('a')] <= 0:
                    cnt -= 1
                l += 1

            ans += (r - l + 1)
            r += 1

        return ans

    def substrCount(self, s: str, k: int) -> int:
        return self.upto(s, k) - self.upto(s, k - 1)

#{
#Driver Code Starts
#Initial Template for Python 3

t = int (input ())
for tc in range (t):
    s = input ()
    k = int (input ())
    ob = Solution()
    print (ob.substrCount (s, k))
#} Driver Code Ends