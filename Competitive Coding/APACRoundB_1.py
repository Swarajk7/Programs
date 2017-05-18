import math
def nCr(n,r):
    f=math.factorial
    a=f(n-1)
    b=f(r-1)
    q=n-r+1
    c=f(n)
    d=f(q)
    f=f(n-r)
    e=(a*c)/(f*b*d)
    return e%1000000007
t=int(input())
for ii in range(1,t+1):
    a,b=map(int,raw_input().split())
    print 'Case #%d: %d '%(ii,nCr(b,a))
    
