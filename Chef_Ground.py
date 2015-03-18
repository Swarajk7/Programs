t=int(input())
for ix in range(t):
    n,m=map(int,raw_input().split())
    a=map(int,raw_input().split())
    p=max(a)
    s=0
    for i in a:
        s=s+p-i
    if s>m: print "No"
    else:
        m=m-s
        if m%n==0: print "Yes"
        else: print "No"
    
