import math
def divisorGenerator(n):
    ar=[]
    for i in range(2,int(math.sqrt(n))+1):
        if n%i is 0:
            ar.append(i)
            if i != n/i:
                ar.append(n/i)
    ar.append(1)
    return ar

def is_sqr(p):
    print p
    q=int(p**0.5)
    return p==q*q
def is_fibonacci(n):
    if n==0 or n==1: return True
    k=n*n
    return is_sqr(k-4) or is_sqr(k+4)

t=int(input())
for i in range(1,t+1):
    n,m=map(int,raw_input().split())
    aa=list(divisorGenerator(n))
    #print aa,
    aa=sum(aa)
    aa=aa%m
    aa=len(list(divisorGenerator(aa)))
    print aa
    if is_fibonacci(aa): print "Case #%d: YES."%(i)
    else: print "Case #%d: NO."%(i)
