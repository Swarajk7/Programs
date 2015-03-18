import math
def factors(n):
    if n==1: return 1
    rootn=(n**0.5)
    #print rootn
    ans=2
    val=2
    while val<rootn:
        if n%val==0:
            p=n/val
            ans+=2
        val+=1
        #print val
    if rootn==val:
        ans+=1
    return ans
t=int(input())
for ii in range(t):
    n=ii+1
    print factors(n)
