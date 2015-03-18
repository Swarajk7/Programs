dp=[ [[-1]*20 for i in range(4)] for i in range(205) ]
def f(N,C,RV,i):
    #print i,len(N),C,RV
    if C<0: return 0
    if i==len(N):
        if RV==0:
            #print K
            return 1
        else: return 0
    if dp[C][RV][i]!=-1: return dp[C][RV][i]
    ans=0
    v=ord(N[i])-48
    l=v-C
    r=v+C
    k=0
    if i==0: k=1
    for j in range(k,10):
        if j>=l and j<=r:
            xx=(RV*10+j)%3
            cost=abs(v-j)
            ans+=f(N,C-cost,xx,i+1)
    dp[C][RV][i]=ans
    return ans

n,k=raw_input().split()
k=int(k)
print f(n,k,0,0)
    
