# User function Template for python3
class Solution:

    def min_lights(self, h, n):
        # code here
        l = []
        for j, i in enumerate(h):
            if i >= 0:
                l.append([j-i, j+i])
        l.sort(key=lambda x: x[0])
        m = len(l)
        target = 0
        cnt = 0
        i = 0
        while i < m:
            mx = target
            while i < m and ((l[i][1] >= target >= l[i][0]) or l[i][1] <= target):
                mx = max(mx, l[i][1]+1)
                i += 1
            if mx != target:
                cnt += 1
            else:
                i += 1
            if mx >= n:
                return cnt
            target = mx
        if target < n:
            return -1
        return cnt


# {
 # Driver Code Starts
# Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        hallway = [int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.min_lights(hallway, n))


# } Driver Code EndsF
