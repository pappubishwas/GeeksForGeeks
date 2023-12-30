#User function Template for python3

from collections import defaultdict
class Solution:
    
    #Complete this function
    
    #Function to return the name of candidate that received maximum votes.
    def winner(self,arr,n):
        # Your code here
        # return the name of the winning candidate and the votes he recieved
        count_vote=defaultdict(int)
        
        for name in arr:
            count_vote[name]+=1
        
        winner_name=""
        winner_vote=0
        
        for name,vote in count_vote.items():
            if vote>winner_vote:
                winner_name=name
                winner_vote=vote
            elif vote==winner_vote and name<winner_name:
                winner_name=name
        
        return [winner_name,str(winner_vote)]        



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    T=int(input())
    for _ in range(T):
        
        n=int(input())
        arr=input().strip().split()
        
        result = Solution().winner(arr,n)
        print(result[0],result[1])
# } Driver Code Ends