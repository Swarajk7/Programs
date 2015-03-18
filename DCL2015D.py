n,x,y=map(int,raw_input().split())
def dist(p1,p2):
    k1=p1[0]-p2[0]
    k2=p1[1]-p2[1]
    return k1**2+k2**2
v=[(0,0)]
for zz in range(n):
    a,b=map(int,raw_input().split())
    v.append((a,b))
v.append((x,y))
N=len(v)
ar=[ [0]*(N) for i in range(N) ]
for i in range(len(v)):
    for j in range(len(v)):
        ar[i][j]=dist(v[i],v[j])
start=0
end=len(v)-1
visited=[False]*N
d=[10000000000000]*N
visited[start]=True
d[start]=0
while not visited[end]:
    minInd=-1
    minVal=10000000000000
    for j in range(N):
        if j!=start and visited[j]==False:
            if d[start]+ar[start][j]<d[j]:
                d[j]=d[start]+ar[start][j]
                if d[j]<minVal:
                    minVal=d[j]
                    minInd=j
    start=minInd
    visited[start]=True
print d[end],v
                

    
    
