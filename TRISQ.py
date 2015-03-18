t=int(input())
for zzz in range(t):
    B=int(input())
    ans=0
    B=B-2
    while B>0:
        p=B/2
        ans+=p
        B=2*p-2
    print ans
        
