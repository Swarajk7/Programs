import itertools
def check(ar):
    a=ar[0];b=ar[1];c=ar[2];
    if c==4*a-b: return True
    else: return False
n=int(input())
flag=False
if n==0:
    print "YES"
    print "1"
    print "1"
    print "3"
    print "3"
    flag=True
elif n==1:
    a=int(raw_input())
    print "YES"
    print a
    print 3*a
    print 3*a
    flag=True
elif n==2:
    a=int(raw_input())
    b=int(raw_input())
    print "YES"
    d=3*a
    c=4*a-b
    if d<1 or c<1:
        d=3*b
        c=4*b-a
    print c
    print d
    flag=True
elif n==3:
    a=int(raw_input())
    b=int(raw_input())
    c=int(raw_input())
    ar=[a,b,c]
    for i in itertools.permutations(ar):
        if check(i):
            print "YES"
            a=i[0];b=i[1];c=i[2];
            print 3*a
            flag=True
            break
else:
    a=int(raw_input())
    b=int(raw_input())
    c=int(raw_input())
    d=int(raw_input())
    ar=[a,b,c,d]
    for i in itertools.permutations(ar):
        a=i[0];b=i[1];c=i[2];d=i[3]
        if d==3*a and c==3*a-b:
            print "YES"
            flag=True
            break
if not flag: print "NO"
