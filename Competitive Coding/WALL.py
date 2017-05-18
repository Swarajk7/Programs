def fun(n,a,b,m,d,ind,H):
    x=[0]*n
    z=[(0,0)]
    for i in range(1,n):
        x[i]=x[i-1]+d[ind]
        ind=(a*ind+b)%m
        if i%2==0: z.append((x[i],0))
        else: z.append((x[i],H))
    #print z
    return area(z)
    
import math
def area1(a, b, c):
    def distance(p1, p2):
        return math.hypot(p1[0]-p2[0], p1[1]-p2[1])

    side_a = distance(a, b)
    side_b = distance(b, c)
    side_c = distance(c, a)
    s = 0.5 * ( side_a + side_b + side_c)
    return math.sqrt(s * (s - side_a) * (s - side_b) * (s - side_c))

def area(z):
    tot_area=0
    for i in range(0,n,2):
        #print i
        if i+2<=n-1:
            tot_area+=area1(z[i],z[i+1],z[i+2])
        else: break
    if i==n-2:
        tot_area+=(0.5*(z[i+1][0]-z[i][0])*max([z[i][1],z[i+1][1]]))
    return tot_area
t=int(input())
for i in range(t):
    H=int(input())
    n,m=map(int,raw_input().split())
    a,b,ind=map(int,raw_input().split())
    d=map(int,raw_input().split())
    print '%0.1f'%fun(n,a,b,m,d,ind,H)
