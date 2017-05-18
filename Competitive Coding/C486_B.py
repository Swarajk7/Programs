n,m=map(int,raw_input().split())
B= [ [] for i in range(n) ]
for i in range(n):
    X=map(int,raw_input().split())
    B[i]=X
A = [ [0]*m for i in range(n) ]
for i in range(n):
    for j in range(m): A[i][j]=B[i][j]
for i in range(n):
    for j in range(m):
        if B[i][j]==0:
            for k in range(m): A[i][k]=0
            for k in range(n): A[k][j]=0
BN= [ [0]*m for i in range(n) ]

for i in range(n):
    for j in range(m):
        s1=0;s2=0
        for k in range(m): s1|=A[i][k]
        for k in range(n): s2|=A[k][j]
        BN[i][j]=s1|s2

flag = True
for i in range(n):
    for j in range(m):
        if B[i][j]!=BN[i][j]:
            flag=False
            break
    if not flag: break
            
if flag:
    print "YES"
    for i in range(n):
        for j in range(m): print A[i][j],
        print ''
else:
    print "NO"
