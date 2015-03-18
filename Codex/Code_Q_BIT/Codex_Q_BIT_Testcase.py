def pri(t,a,b):
    print t
    for i in a: print i,
    print ''
    for i in b: print i,
    print ''
t=10
print t
for i in range(t):
    n=100000
    import random
    a=range(100,100001,1000)*(n/100)
    b=range(100,100001,1000)*(n/100)
    random.shuffle(a)
    random.shuffle(b)
    pri(n,a,b)
