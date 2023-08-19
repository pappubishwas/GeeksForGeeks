#User function Template for python3

#Function to find a continuous sub-array which adds up to a given number.
class Solution:
    def subArraySum(self,arr, n, s): 
       #Write your code here
       sum1=0
       l=0
       r=0
       lt=[]
       if s==0:
           lt.append(-1)
           return lt
       while r<n or sum1>=s:
           if sum1<s:
               sum1+=arr[r]
               r+=1
           elif sum1==s:
                lt.append(l+1)
                lt.append(r)
                return lt
           else:
                sum1-=arr[l];
                l+=1
       lt.append(-1)        
       return lt; 


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

def main():
        T=int(input())
        while(T>0):
            
            NS=input().strip().split()
            N=int(NS[0])
            S=int(NS[1])
            
            A=list(map(int,input().split()))
            ob=Solution()
            ans=ob.subArraySum(A, N, S)
            
            for i in ans:
                print(i, end=" ")
                
            print()
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends