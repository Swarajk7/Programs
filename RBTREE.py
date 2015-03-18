ar=[0]*32
ar[0]=0
import math
for i in range(1,len(ar)):
    ar[i]=1-ar[i-1]
def change():
    for i in range(len(ar)):
        ar[i]=1-ar[i]
def get(l):
    z=int(math.floor(math.log(l,2)))
    return z
def CalB(l,r):
    if l==r:
        if ar[get(l)]==0: return 1
        else: return 0
    else:
        if l<r:
            if ar[get(r)]==0: return 1+CalB(l,r/2)
            else: return CalB(l,r/2)
        else:
            if ar[get(l)]==0: return 1+CalB(l/2,r)
            else: return CalB(l/2,r)
def CalR(l,r):
    if l==r:
        if ar[get(l)]==1: return 1
        else: return 0
    else:
        if l<r:
            if ar[get(r)]==1: return 1+CalR(l,r/2)
            else: return CalR(l,r/2)
        else:
            if ar[get(l)]==1: return 1+CalR(l/2,r)
            else: return CalR(l/2,r)

n=int(input())
for i in range(n):
    s=raw_input().split()
    if s[0]=='Qi':
        change()
    elif s[0]=='Qb':
        print CalB(int(s[1]),int(s[2]))
    else:
        print CalR(int(s[1]),int(s[2]))
    
