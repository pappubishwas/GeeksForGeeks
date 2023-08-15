#User function Template for python3

#User function Template for python3
class Solution:
    def maxOnes(self, a, n):
        # Your code goes here
        count=0
        sum=0 
        ans=0
        for i in range(0,n):
            if a[i]==1:
                a[i]=-1
                count+=1
            else:
                a[i]=1
        for i in range(0,n):
            sum+=a[i]
            ans=max(ans,sum)
            if sum<0:
                sum=0
                
        return ans+count            



#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob=Solution()
        print(ob.maxOnes(a, n))

        T -= 1


if __name__ == "__main__":
    main()



# } Driver Code Ends