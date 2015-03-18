import random
t=10
l=1
r=10**5
n=10**5
print t
for i in range(t):
    print n
    for i in range(n):
        a=random.randint(l,r-2)
        b=random.randint(a,r)
        print a,b
