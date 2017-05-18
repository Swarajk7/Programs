t=int(input())
for t1 in range(1,t+1):
    s=raw_input()
    ar=[s]
    for i in range(len(s)):
        for j in range(i+1,len(s)):
            z=list(s)
            k=z[i]
            z[i]=z[j]
            z[j]=k
            z=''.join(z)
            #print z
            if z[0]!='0':
                ar.append(z)
    ar.sort()
    print "Case #"+str(t1)+":",
    print ar[0],ar[-1]
