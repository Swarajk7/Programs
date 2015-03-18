s,n=map(int,raw_input().split())
w=[]
p=[]
dp=[ [-1]*2005 for i in range(2005) ]
for zz in range(n):
    a,b=map(int,raw_input().split())
    w.append(a)
    p.append(b)
def rec(i,W):
    #print i,W
    if i==n:
        if W>=0: return 0
        else: return -999999
    if dp[i][W]!=-1: return dp[i][W]
    k=max([rec(i+1,W),p[i]+rec(i+1,W-w[i])])
    dp[i][W]=k
    return k
print rec(0,s)
    
