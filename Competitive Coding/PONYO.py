t=int(input())
for ii in range(t):
    a=raw_input()
    ans=0
    mxans=-1
    for i in a:
        if i=='R':
            ans+=1
        else:
            if ans>mxans: mxans=ans
            ans=0
    print mxans
