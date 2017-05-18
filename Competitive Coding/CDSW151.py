t=int(input())
for i in range(t):
    n,m=map(int,raw_input().split())
    ar=map(int,raw_input().split())
    ans=0
    ansInd=0
    for i in range(m): ans^=ar[i]
    for i in range(m,n):
        ans1=(ans^ar[i-m])^ar[i]
        #print ans1,ans,ar[i-m],ar[i]
        if ans>=ans1:
            ans=ans1
            ansInd=i-m+1
    print ansInd+1
