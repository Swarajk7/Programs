n,m=map(int,raw_input().split())
g=[ [] for i in range(n) ]
for i in range(m):
    u,v=map(int,raw_input().split())
    g[u].append(v)
visited=[False]*n
stack=[]
def dfs(s):
    if visited[s]: return
    visited[s]=True
    for i in g[s]:
        dfs(i)
    stack.append(s)

for i in range(n):
    dfs(i)
print stack
