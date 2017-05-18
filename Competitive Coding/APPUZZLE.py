t=int(input())
for ii in range(t):
    x,y,z=map(int,raw_input().split())
    n=2*z/(x+y)
    d=(x-y)/(5-n)
    a=x-2*d
    print n
    for i in range(n):
        print a+i*d,
