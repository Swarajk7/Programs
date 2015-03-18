n,q=map(int,raw_input().split())
ar=map(int,raw_input().split())
for ii in range(q):
    xx=raw_input().split()
    if xx[0]=='0':
        ar[int(xx[1])]=int(xx[2])
    else:
        z=int(xx[1])
        mx=0
        for i in ar:
            mx=max(mx,z^i)
        print mx
        
