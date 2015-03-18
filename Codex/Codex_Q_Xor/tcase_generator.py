import random
n=10000
q=100000
p=0.6
ran=1000000000
a=q*p
b=q*(1-p)
print n,q
ar=[]
for i in range(n):
    ar.append(random.randint(1,ran))
for i in ar:
    print i,
print ''
for zz in range(q):
    x=random.randint(0,1)
    if (x==0 and a>0) or (x==1 and b<=0):
        print '0',random.randint(0,n-1),random.randint(1,ran)
    else:
        print '1',random.randint(1,ran)
    
