# Function to find the leaders in the array.
def leaders(a, n):
    ans = []
    ans.append(a[0])
    for i in range(1, n):
        if ans[-1] >= a[i]:
            ans.append(a[i])
        else:
            while ans and ans[-1] < a[i]:
                ans.pop()
            ans.append(a[i])
    return ans

# Main code
t = int(input())  # Number of test cases
for _ in range(t):
    n = int(input())  # Size of the array
    a = list(map(int, input().split()))  # Elements of the array
    
    # Calling the leaders() function
    v = leaders(a, n)
    
    # Printing the elements of the vector
    for item in v:
        print(item, end=" ")
        
    print()
