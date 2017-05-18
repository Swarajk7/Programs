t=int(input())
for zz in range(t):
    n=int(input())
    ar=set(map(int,raw_input().split()))
    if n==len(ar): print "YES"
    else: print "NO"
