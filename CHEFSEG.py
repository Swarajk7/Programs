import math
t=int(input())
for i in range(t):
    x,k=map(int,raw_input().split())
    z=int(math.ceil(math.log(k+1,2)))
    z=2**z;x=float(x)
    seg_len=x/z
    init=seg_len
    print "%.9f" % (init+2*seg_len*(k-z/2))
