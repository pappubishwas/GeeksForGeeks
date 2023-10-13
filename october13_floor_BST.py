# User function Template for python3

class Solution:
    def findClose(self, root, x, ans):
        if root == None:
            return
        if root.data == x:
            ans[0] = x
            return
        elif root.data > x:
            self.findClose(root.left, x, ans)
        else:
            ans[0] = max(ans[0], root.data)
            self.findClose(root.right, x, ans)

    def floor(self, root, x):
        # Code here
        ans = [-1]
        self.findClose(root, x, ans)
        return ans[0]

# {
 # Driver Code Starts
# Initial Template for Python 3


class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


def insert(tree, val):
    if (tree == None):
        return Node(val)
    if (val < tree.data):
        tree.left = insert(tree.left, val)
    elif (val > tree.data):
        tree.right = insert(tree.right, val)
    return tree


if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        n = int(input())
        arr = list(map(int, input().split()))
        root = None
        for k in arr:
            root = insert(root, k)
        s = int(input())
        obj = Solution()
        print(obj.floor(root, s))
# } Driver Code Ends
