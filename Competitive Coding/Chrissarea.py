def cross(a, b):
    c = [a[1]*b[2] - a[2]*b[1],
         a[2]*b[0] - a[0]*b[2],
         a[0]*b[1] - a[1]*b[0]]

    k= c[0]**2+c[1]**2+c[2]**2
    return (k**0.5)/2.0
t=int(input())
for i in range(t):
    a=map(float,raw_input().split())
    b=map(float,raw_input().split())
    print '%.3f'%(cross(a,b))
