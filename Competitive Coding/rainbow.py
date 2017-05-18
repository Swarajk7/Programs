import math
n=int(input())
def func(n):
    #print n
    n=n-1
    return (n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5)/720)%1000000007
if n<13: print '0'
elif n==13: print '1'
else: print func(int(math.ceil(n/2.0)))
