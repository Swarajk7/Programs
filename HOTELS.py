n,k=map(int,raw_input().split())
v=map(int,raw_input().split())
dp=[0]*n
if v[0]<=k: dp[0]=v[0]
l=0
mx=dp[0]
for i in range(1,n):
    val=v[i]+dp[i-1]
    #print val,l
    while l<=i and val>k:
        val-=v[l]
        l+=1
        #print l,i
    if l==i: dp[i]=0
    else: dp[i]=val
    if dp[i]>mx:
        mx=dp[i]
print mx
