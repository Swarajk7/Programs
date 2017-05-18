def getDist(x1,y1,x2,y2):
    k=(x2-x1)**2+(y2-y1)**2
    return k
def ax(a,b): return (int(a),int(b))
def hell(a,b,z,m1):
    x=a[0]+z
    y=m1*(x-a[0])+a[1]
    ans=[]
    ans.append(ax(x,y))
    x=b[0]+z
    y=m1*(x-b[0])+b[1]
    ans.append(ax(x,y))
    return ans
def gen(a,b,k):
    ans=[]
    ans.append((a[0],a[1]+k))
    ans.append((b[0],b[1]+k))
    ans1=ans
    ans=[]
    ans.append((a[0],a[1]-k))
    ans.append((b[0],b[1]-k))
    return [ans1,ans]
def gen1(a,b,k):
    ans=[]
    ans.append((a[0]+k,a[1]))
    ans.append((b[0]+k,b[1]))
    ans1=ans
    ans=[]
    ans.append((a[0]-k,a[1]))
    ans.append((b[0]-k,b[1]))
    return [ans1,ans]
def sqr(a,b):
    k=getDist(a[0],a[1],b[0],b[1])
    if(b[0]==a[0]): return gen1(a,b,int(k**0.5))
    m=(b[1]-a[1])/(b[0]-a[0])
    if(m==0): return gen(a,b,int(k**0.5))
    m1=-1.0/m
    z=k/(m*m+1)
    z=z**0.5
    ans1=hell(a,b,z,m1)
    ans2=hell(a,b,-1*z,m1)
    return [ ans1,ans2]
t=int(input())
ar=[]
d=set()
def get(a):
    cnt=0
    if a[0] not in d: cnt+=1
    if a[1] not in d: cnt+=1
    return cnt
 
for i in range(t):
    a,b=map(int,raw_input().split())
    ar.append((a,b))
    d.add((a,b))
mn=1000
for i in range(t):
    for j in range(i+1,t):
        x=sqr(ar[i],ar[j])
        val=get(x[0])
        mn=min(val,mn)
        val=get(x[1])
        mn=min(val,mn)
if t==1: mn=3
if t==0: mn=4
print mn
 
