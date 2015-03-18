t=int(input())
for i in range(t):
    n=float(input())
    ans=0
    for i in range(1,int(n+1)):
        ans+=1.0/i
    print "%.3f" % (ans)
        
