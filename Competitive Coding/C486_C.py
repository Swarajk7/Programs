n,p=map(int,raw_input().split())
a=raw_input()
k=n/2
r=-1;l=-1
p-=1
if p>=k: p = n-p-1
#print p
for i in range(p,k):
    if a[i]!=a[n-1-i]:
        r=i
for i in range(p-1,-1,-1):
    if a[i]!=a[n-1-i]:
        l=i
ans=-1
#print l,r
if l==r and l==-1: ans=0
else:
    z=-1
    if r==-1: z=p-l
    elif l==-1: z=r-p
    else: z=min(p-l+r-l,r-p+r-l)
    ans=z
    for i in range(k):
        p1=ord(min(a[i],a[n-1-i]))-97
        p2=ord(max(a[i],a[n-1-i]))-97
        ans_t=min(p2-p1,26-p2+p1)
        #print p1,p2,ans_t
        ans += ans_t
print ans
