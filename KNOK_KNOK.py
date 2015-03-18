import math
def basecase(n):
    if n in [0,1,2]: return 1
    elif n in [3,4]: return 3
    elif n in [5,6]: return 15
    else: return 105
def R(n):
    #print n
    if n<=10: return basecase(n)
    else:
        z = ( R(int(math.ceil(n/5.0)))*R(int(math.ceil(n/10.0))))%(10**9)
        z = (z * pow(2,int(math.ceil(n/4.0)),10**9))%(10**9)
        return z
z=[(1,2),(1,3),(1,5),(2,3),(2,5),(3,5),(2,1),(3,1),(5,1),(3,2),(5,2),(5,3),(3,4),(4,3),(4,5),(5,4),(1,4),(4,1)]
t=int(input())
for i in range(t):
    n=int(input())
    zz=R(n)
    maxans=0
    #print zz
    for i in z:
        x=zz*i[0]
        y=zz*i[1]
        maxans=max(maxans,pow(x,y,10**9))
    print maxans
    
    
