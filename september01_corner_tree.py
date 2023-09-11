class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def print_corner(root):
    ans = [root]
    left1 = root.left
    right1 = root.right
    while ans:
        temp = []
        i = 0
        while i < len(ans):
            if ans[i].left:
                temp.append(ans[i].left)
            if ans[i].right:
                temp.append(ans[i].right)
            i += 1
        if len(ans) == 1:
            print(ans[0].data, end=" ")
        else:
            print(ans[0].data, end=" ")
            print(ans[-1].data, end=" ")
        ans = temp

# Usage
# Construct the tree
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

print_corner(root)
