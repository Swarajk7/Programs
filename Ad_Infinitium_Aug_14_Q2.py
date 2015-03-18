t=int(input())
for i in range(t):
    n=int(input())
    x=1+8*n
    y=int(x**0.5)
    print x,y
    if y*y==x and (int(y)-1)%2==0:
        print "Go On Bob",(int(y)-1)/2
    else:
        print "Better Luck Next Time"
