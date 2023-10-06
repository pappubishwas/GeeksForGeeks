"""
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
class Node:

	# Constructor to initialize the node object
	def __init__(self, data):
		self.data = data
		self.next = None

"""
class Solution:
    def reverselist(self,even):
        curr=even
        prev=None
        temp=None
        while curr!=None:
            temp=curr.next
            curr.next=prev
            prev=curr
            curr=temp
        return prev    
    def rearrange(self, head):
        # Code here
        even=None
        temp1=head
        temp2=None
        if head==None or head.next==None:
            return
        while temp1.next!=None:
            if even==None:
                temp2=temp1.next
                even=temp2
                temp1.next=temp1.next.next
                if temp1.next!=None:
                    temp1=temp1.next
            else:
                temp2.next=temp1.next
                temp1.next=temp1.next.next
                temp2=temp2.next
                if temp1.next!=None:
                    temp1=temp1.next
        temp2.next=None
        temp1.next=self.reverselist(even)    
                        
            



#{ 
 # Driver Code Starts
# Node Class
class Node:
    # Constructor to initialize the node object
    def __init__(self, data):
        self.data = data
        self.next = None


# Linked list class contains node object
class LinkedList:
    # Constructor to initialize head
    def __init__(self):
        self.head = None

    # Function to insert a new node at the beginning
    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data, end=" ")
            temp = temp.next
        print()


# Code execution starts here
if __name__ == '__main__':
    t = int(input())
    while (t > 0):
        llist = LinkedList()
        n = int(input())
        values = list(map(int, input().strip().split()))
        for i in reversed(values):
            llist.push(i)
            
        Solution().rearrange(llist.head)
        llist.printList()
        t -= 1
# Contributed by: Harshit Sidhwa
# } Driver Code Ends