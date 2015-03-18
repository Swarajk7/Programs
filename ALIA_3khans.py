def nextN1(n):
    p=bin(n)
    p=list(p[2:])
    p.insert(0,'0')
    r1=-1
    r0=-1
    for i in range(len(p)-1,-1,-1):
        #print i,
        if p[i]=='1' and r1==-1: r1=i
        if p[i]=='0' and r1!=-1 and r0==-1: r0=i
    k=p[r0]
    p[r0]=p[r1]
    p[r1]=k
    k=p[r0+1:]
    k.sort()
    #print p[:r0+1],k
    s=''
    for i in p[:r0+1]: s+=i
    for i in k: s+=i
    return int(s,2)

def nextN(n):
    nxt=0
    if n!=0:
        r=n&(-n)
        nh1b=n+r
        rop=n^nh1b
        rop=rop/r
        rop=rop>>2
        nxt=nh1b|rop
    return nxt

def prevN1(n):
    p=bin(n)
    p=list(p[2:])
    r1=-1
    r0=-1
    for i in range(len(p)-1,-1,-1):
        if p[i]=='0': r0=i
    if r0==-1: return -1
    for i in range(r0-1,-1,-1):
        if p[i]=='1':
            r1=i
            break
    k=p[r0]
    p[r0]=p[r1]
    p[r1]=k
    k=p[r1+1:]
    k.sort(reverse=True)
    #print p,k,r0,r1
    s=''
    for i in p[:r1+1]: s+=i
    for i in k: s+=i
    return int(s,2)

def prevN(y):
    z=y+1
    if not z&(z-1): return -1
    t = y + 1;
    u = t ^ y;
    v = t & y;
    x = v - (v & -v) / (u + 1);
    return x
def is_gp(a,b,c):
    return b/a == c/b
t=int(input())
s=0.0
w=0.0
for i in range(t):
    #n=int(input())
    n=i+1
    k=nextN(n)
    q=prevN(n)
    if n==0:
        continue
    s+=(k-q)
    if is_gp(q*1.0,n*1.0,k*1.0):
        w+=1
    print i,k-q
print '%0.6f %0.6f' %(w/t,s/t)
    
