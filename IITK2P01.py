import math
log=math.log
t=int(input())
for i in range(t):
    n,k=map(int,raw_input().split())
    ans=0
    while n!=0:
        z=int(log(n)/log(k))
        n-=k**z
        ans+=1
        #print ans,n,z
    print ans
        
