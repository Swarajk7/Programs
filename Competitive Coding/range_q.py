n=int(input())
ar=map(int,raw_input().split())
hsh=[[0]*n for i in range(105)]
hsh[ar[0]][0]=1
for i in range(1,n):
    for j in range(102):
        #print i,j
        if ar[i]==j: hsh[j][i]=1+hsh[j][i-1]
        else:  hsh[j][i]=hsh[j][i-1]
q=int(input())
for z in range(q):
    a,b,c=map(int,raw_input().split())
    ans=0
    if a!=0: ans=hsh[c][b]-hsh[c][a-1]
    else: ans=hsh[c][b]
    print ans
