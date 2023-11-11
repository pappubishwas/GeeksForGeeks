#User function Template for python3

class Solution:
    def areIsomorphic(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False

        mapping_s1_to_s2 = {}
        mapping_s2_to_s1 = {}

        for char_s1, char_s2 in zip(s1, s2):
            if char_s1 in mapping_s1_to_s2:
                if mapping_s1_to_s2[char_s1] != char_s2:
                    return False
            elif char_s2 in mapping_s2_to_s1:
                if mapping_s2_to_s1[char_s2] != char_s1:
                    return False
            else:
                mapping_s1_to_s2[char_s1] = char_s2
                mapping_s2_to_s1[char_s2] = char_s1

        return True




#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys
from collections import defaultdict

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
        ob = Solution()
        if(ob.areIsomorphic(s,p)):
            print(1)
        else:
            print(0)
# } Driver Code Ends