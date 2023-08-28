#User function Template for python3

class Solution:
    def reverseWord(self, s):
        s_list = list(s)  # Convert the string to a list
        st = 0
        lt = len(s_list) - 1
        while st < lt:
            s_list[st], s_list[lt] = s_list[lt], s_list[st]
            st += 1
            lt -= 1
        
        return ''.join(s_list)  # Convert the list back to a string


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while(t>0):
        s = input()
        ob = Solution()
        print(ob.reverseWord(s))
        t = t-1

# } Driver Code Ends
