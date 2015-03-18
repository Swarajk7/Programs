def f(x,y,m,x1,y1):
    return y-m*x+(m*x1-y1)
t=int(input())
for i in range(t):
    x1,y1,x2,y2,xm,ym=map(int,raw_input().split())
    m=(y2-y1)/((x2-x1)*1.0)
    a=f(0,0,m,x1,y1)
    b=f(xm,ym,m,x1,y1)
    m1=ym/(xm*1.0)
    if a*b>=0:
        if m==m1:
            if xm*xm+ym*ym<x1*x1+y1*y1: print "YES"
            else: print "NO"
        else: print "YES"
    else: print "NO"
