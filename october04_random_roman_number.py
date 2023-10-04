#User function Template for python3

class Solution:
    def romanToDecimal(self, s: str) -> int:
        # Dictionary to map Roman numerals to decimal values
        roman_dict = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        
        i = 0
        sum = 0
        
        while i < len(s):
            # Check if we need to subtract
            if i+1<len(s) and roman_dict[s[i]]<roman_dict[s[i+1]]:
                sum+=(roman_dict[s[i+1]]-roman_dict[s[i]])
                i+=1
            else:
                sum+=roman_dict[s[i]]
            i+=1
        return sum    




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t = int(input())
    for _ in range(t):
        ob = Solution()
        S = input()
        print(ob.romanToDecimal(S))
# } Driver Code Ends