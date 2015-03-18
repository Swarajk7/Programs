ans=0
for a in range(100,999):
    for b in range(100,999):
        c=a*b
        z=0;v=c
        while v!=0:
            k=v%10
            z=z*10+k
            v/=10
        if z==c:
            ans=max(ans,c)
print ans
