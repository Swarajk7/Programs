t=int(input())
for ii in range(t):
    n=int(input())
    ar=map(int,raw_input().split())
    b=[]
    for i in reversed(ar):
        b.append(i)
    mx=-1
    for i in range(10):
        if i not in ar: continue
        x=ar.index(i)
        y=b.index(i)
        y=n-y-1
        mx=max([mx,y-x+1])
    print mx
