w=[]
h=[]
t=int(input())
def rec(W,H):
    if W<=0 or H<=0: return 0
    ans=W*H
    for i in range(len(w)):
        if W>=w[i] and H>=h[i]:
            ans=min([ans,rec(W-w[i],h[i])+rec(W-w[i],H-h[i])+rec(w[i],H-h[i])])
    return ans
for zzz in range(t):
    W,H=map(int,raw_input().split())
    n=int(input())
    for i in range(n):
        a,b=map(int,raw_input().split())
        w.append(a)
        h.append(b)
    print rec(W,H)
