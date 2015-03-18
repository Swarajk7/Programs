d,n=map(int,raw_input().split())
a=map(int,raw_input().split())
g=[ [] for i in range(n+1) ]
for i in range(n-1):
    u,v=map(int,raw_input().split())
    g[u].append(v)
    g[v].append(u)
mn=1000000000
mx=-1
ans=0
def dfs(i,par):
    global mx,ans
    global mn
    for j in g[i]:
        if j!=par:
            dfs(j,i)
    mn=min(a[i-1],mn)
    mx=max(a[i-1],mx)
    if mx-mn<=d:
        ans+=1
for i in range(n+1):
    global mx
    global mn
    mn=1000000000
    mx=-1
    dfs(i,-1)
print ans
