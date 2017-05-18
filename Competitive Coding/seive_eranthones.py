def sieve(n):
    "Return all primes <= n."
    np1 = n + 1
    s = list(range(np1)) # leave off `list()` in Python 2
    s[1] = 0
    sqrtn = int(round(n**0.5))
    for i in range(2, sqrtn + 1): # use `xrange()` in Python 2
        if s[i]:
            # next line:  use `xrange()` in Python 2
            s[i*i: np1: i] = [0] * len(range(i*i, np1, i))
    return filter(init7a, s)
def init7(a):
    return '7' in str(a)
ans=sieve(1000000)
ans2=[0]*1000002
hsh=[False]*1000002
j=0
ans2[0]=0
for i in range(1,len(ans2)):
    if j<len(ans): 
        if i<ans[j]:
            ans2[i]=ans2[i-1]
        elif i==ans[j]:
            hsh[i]=True
            ans2[i]=1+ans2[i-1]
            j+=1
    else:
        ans2[i]=ans2[i-1]
t=int(input())
for xx in range(t):
    a,b=map(int,raw_input().split())
    if hsh[a]: print ans2[b]-ans2[a]+1
    else:
        k=ans2[b]-ans2[a]
        if k==0:
            print "-1"
        else:
            print k


