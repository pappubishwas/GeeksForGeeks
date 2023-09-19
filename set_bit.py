#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math



# } Driver Code Ends
#User function Template for python3

class Solution:
    
    #Function to find position of first set bit in the given number.
    def getFirstSetBit(self,n):
        #Your code here
        c=1
        while n>0:
            if n%2==1:
                return c;
            else:
                c+=1
            n//=2    
        return 0    

#{ 
 # Driver Code Starts.
    
    
def main():
    
    T=int(input())
    
    while(T>0):
        
        
        n=int(input())
        ob=Solution()
        
        print(ob.getFirstSetBit(n))
        
        
        T-=1
    
    




if __name__=="__main__":
    main()
# } Driver Code Ends