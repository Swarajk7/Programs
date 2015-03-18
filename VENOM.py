import math
def get(h,p,a):
    if h<=p: return 1
    b=p-2*a
    z=2*(a-h)
    z=(b*b-4*p*z)**0.5
    r=-b+z;r=r/(2*p)
    return int(math.ceil(r))*2-1
t=int(input())
for i in range(t):
    h,p,a=map(int,raw_input().split())
    print get(h,p,a)
