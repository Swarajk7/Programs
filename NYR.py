t=int(input())
for zzz in range(t):
    gp,gc,gf=map(int,raw_input().split())
    n=int(input())
    ar=[]
    for i in range(n):
        p,c,f=map(int,raw_input().split())
        ar.append((p,c,f))
    flag = False
    for z in range(1<<n):
        j=0
        tp=0;tc=0;tf=0;
        while z!=0:
            k=z&1
            z>>=1
            if k==1:
                tp+=ar[j][0]
                tc+=ar[j][1]
                tf+=ar[j][2]
            j+=1
        if tp==gp and tc==gc and tf==gf:
            flag = True
            break
    if flag: print "yes"
    else: print "no"
            
