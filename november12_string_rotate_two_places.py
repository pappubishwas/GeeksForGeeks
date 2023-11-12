#User function Template for python3


# class Solution:
#     #Function to check if a string can be obtained by rotating
#     #another string by exactly 2 places.
#     def isRotated(self,str1,str2):
#         #code here

class Solution:
    def isRotated(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False

        n = len(s1)

        if s1[0:2] == s2[n - 2:n] and s1[2:n] == s2[0:n - 2]:
            return True

        if s1[0:n - 2] == s2[2:n] and s1[n - 2] == s2[0] and s1[n - 1] == s2[1]:
            return True

        return False


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        s=str(input())
        p=str(input())
        if(Solution().isRotated(s,p)):
            print(1)
        else:
            print(0)
# } Driver Code Ends