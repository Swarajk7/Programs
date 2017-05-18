t=int(input())
for i in range(t):
    n=int(input())
    ar=map(int,raw_input().split())
    z=ar.count(0)
    n-=z
    k=sum(ar)
    if k>=100 and k<100+n: print "YES"
    else: print "NO"
