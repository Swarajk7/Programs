def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(args):
    return reduce(lcm, args)

def gcdm(args):
    return reduce(gcd, args)

def cal():
    B,N=map(int,raw_input().split())
    M=map(int,raw_input().split())
    L=lcmm(M)
    G=gcdm(M)
    CNT=0
    for i in M: CNT+=(L/i)
    Z=((N-1)%CNT)+1
    return schedular(M,L,G,Z)
    
def schedular(M,L,G,C):
    print L,G,C
    c=1
    ass=[0]*len(M)
    time_L=[0]*len(M)
    B=len(M)
    while c<=C:
        flag=True
        for i in range(B):
            if time_L[i]==0:
                ass[i]=c
                c+=1
                time_L[i]=M[i]
            else:
                time_L[i]-=G
                if time_L[i]==0:
                    ass[i]=c
                    c+=1
                    time_L[i]=M[i]
    return ass.index(C)+1
    
T=int(input())
for i in range(1,T+1):
    ans = cal()
    print 'Case #%d: %d'%(i,ans)
    
    
    
    
