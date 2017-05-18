n=int(input())
dp=[-1]*(n+3)
def rec(i,n):
    dp[n+1]=1
    dp[n+2]=1
    for i in range(n,0,-1):
        #print i
        dp[i]=dp[i+1]+dp[i+2]
    return dp[1]
print rec(0,n)
