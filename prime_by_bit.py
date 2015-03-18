primes=[ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61 ]
def nobit(k):
    c=0
    while k!=0:
        if k&1 == 1: c+=1
        k>>=1
    return c
def cnt(i,n,val):
    if nobit(val) in primes : print val
    if val>n : return 0
    if i==0:
        if nobit(val) in primes : return 1
        else: return 0
    k=1<<(i-1)
    val1=val|k
    ans=cnt(i-1,n,val1)
    ans+=cnt(i-1,n,val)
    return ans
print cnt(6,8,0)
