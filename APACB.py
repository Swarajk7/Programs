t=int(input())
for ii in range(t):
    print "Case #%d: "%(ii+1),
    n=int(input())
    ar=map(int,raw_input().split())
    z=[]
    for i in range(0,n+n-1,2):
        #print i
        z.append((ar[i],ar[i+1]))
    #print z
    p=int(input())
    for xx in range(p):
        k=int(input())
        cnt=0
        for y in z:
            
            if k>=y[0] and k<=y[1]:
                cnt+=1
            #print k,y,cnt
        print cnt,
    print ''
    a=raw_input()
