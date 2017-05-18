t=int(input())
for ii in range(t):
    n=int(input())
    a=raw_input()
    ans=a
    for i in range(n):
        j=a[:i]+a[i+1:]
        print j
        for k in range(len(j)+1):
            v=j[:k]+a[i]+j[k:]
            ans=min(ans,v)
    print ans
