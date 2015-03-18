import random
t=10
#max 1000000
#k 80000
print t
for i in range(t):
    n=random.randint(800000,1000000)
    print n
    ar=[random.randint(0,1) for _ in xrange(n)]
    for i in ar: print i,
    sz=70000
    k=700000
    xx=random.randint(0,1)
    x=ar[k:k+sz]
    if xx==0:
        random.shuffle(x)
    print ''
    print sz
    for i in x: print i,
    
