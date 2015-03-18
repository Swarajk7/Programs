import random
n=random.randint(2,16)
k=random.randint(1,200)
print n,k
ar=[[0]*n for i in range(n)]
for i in range(n):
    for j in range(i+1,n):
        ar[i][j]=random.randint(1,100)
        if i==0: ar[i][j]=-1
for i in range(n):
    for j in range(i+1,n):
        ar[j][i]=ar[i][j]
for i in ar:
    for j in i: print j,
    print ''
