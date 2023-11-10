#User function Template for python3
class Solution:
    def printMinNumberForPattern(ob,S):
        # code here 
        ans=""
        st=[]
        n=len(S)
        for i in range(n+1):
            st.append(i+1)
            if i==n or S[i]=='I':
                while st:
                    ans+=str(st.pop())
        return ans            


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        S=str(input())

        ob = Solution()
        print(ob.printMinNumberForPattern(S))
# } Driver Code Ends