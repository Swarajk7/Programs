MOD=1000000007
ZZZ=111
fact=[1]*ZZZ
for i in range(1,ZZZ): fact[i]=(fact[i-1]*i)%MOD
C=[ [-1]*ZZZ for i in range(0,ZZZ) ]
def NCR(N,R):
    if N==R:
        C[N][R]=1
        return 1
    if N==0: return 1
    if R==0:
        C[N][R]=1
        return 1
    if C[N][R]!=-1:
        return C[N][R]
    A=(NCR(N-1,R-1)+NCR(N-1,R))%MOD
    C[N][R]=A
    return C[N][R]
for i in range(ZZZ):
    for j in range(0,i+1):
        #print i,j
        NCR(i,j)
'''for i in range(ZZZ):
    for j in range(0,i+1):
        print C[i][j],
    print ""'''
def ans(m,n):
    
t=int(input())
for t1 in range(1,t+1):
    m,n=map(int,raw_input().split())
    print ans(m,n)
    
