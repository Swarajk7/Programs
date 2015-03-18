def gcd(a,b):
    if b==0: return a
    else: return gcd(b,a%b)
def findGcd(a):
    gcd1=a[0]
    i=1
    while i<n:
        gcd1=gcd(gcd1,a[i])
        if gcd1==1: return 1
        i+=1
    return gcd1
t=int(input())
for ii in range(t):
    n=int(input())
    a=map(int,raw_input().split())
    x=findGcd(a)
    if x!=1: print "-1"
    else: print n
