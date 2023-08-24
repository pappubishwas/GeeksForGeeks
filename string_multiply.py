#User function Template for python3

class Solution:
    def multiplyStrings(num1, num2):
        if num1[0] == '-' and num2[0] == '-':
            num1 = num1[1:]
            num2 = num2[1:]
        elif num1[0] == '-':
            flag = 1
            num1 = num1[1:]
        elif num2[0] == '-':
            flag = 1
            num2 = num2[1:]
        else:
            flag = 0
            
        col = len(num1)
        row = len(num2)
        v1 = [int(digit) for digit in num1]
        v2 = [int(digit) for digit in num2]
        
        mul = [[0] * (col + row) for _ in range(row)]
        
        i = row - 1
        tm = col + row - 1
        t = 0
        while i >= 0:
            j = col - 1
            k = tm
            temp = 0
            while j >= 0:
                mul[t][k] = v2[i] * v1[j] + temp
                temp = mul[t][k] // 10
                mul[t][k] %= 10
                k -= 1
                j -= 1
            if temp > 0:
                mul[t][k] = temp
            i -= 1
            tm -= 1
            t += 1
        
        i = row + col - 1
        tm = col + row - 1
        sum = 0
        st = ""
        while i >= 0:
            j = 0
            while j < row:
                sum += mul[j][i]
                j += 1
            if sum > 9:
                mod = sum % 10
                st = str(mod) + st
                sum = sum // 10
            else:
                st = str(sum) + st
                sum = 0
            i -= 1
        
        while len(st) > 1 and st[0] == '0':
            st = st[1:]
            
        if flag == 1:
            st = "-" + st
            
        return st
    
    #{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t=int(input())
    for i in range(t):
        a,b=input().split()
        print(Solution().multiplyStrings( a.strip() , b.strip() ))

# } Driver Code Ends