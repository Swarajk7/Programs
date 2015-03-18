dp=[ [-1]*40 for i in range(40) ]
def rec(i,l,n,ar):
    global dp
    #print i,l,ar
    if l<0: return 0
    if i==n:
        if l==0: return 1
        else: return 0
    if dp[i][l]!=-1: return dp[i][l]
    ans=rec(i+1,l+1,n,ar)
    if i not in ar: ans=ans+rec(i+1,l-1,n,ar)
    dp[i][l]=ans
    return ans
t=int(input())
for i in range(t):
    n,k=map(int,raw_input().split())
    ar=map(int,raw_input().split())
    dp=[ [-1]*40 for i in range(40) ]
    print rec(1,0,2*n+1,ar)
