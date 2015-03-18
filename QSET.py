n,q=map(int,raw_input().split())
a=raw_input()
c_0=[0]*n;c_1=[0]*n;c_2=[0]*n;
cs=0
def cc(n):
    return (n*(n-1))/2
k=ord(a[0])%3
if k==0:c_0[0]=1
elif k==1: c_1[0]=1
else: c_2[0]=1
for i in range(1,n):
    cs=(cs*10+ord(a[i])-48)%3
    if cs==0: c_0[i]=c_0[i-1]+1;c_1[i]=c_1[i-1];c_2[i]=c_2[i-1];
    elif cs==1: c_0[i]=c_0[i-1];c_1[i]=c_1[i-1]+1;c_2[i]=c_2[i-1];
    else: c_0[i]=c_0[i-1];c_1[i]=c_1[i-1];c_2[i]=c_2[i-1]+1;
for zz in range(q):
    print a,c_0,c_1,c_2
    t,l,r=map(int,raw_input().split())
    if t==1:
        l-=1
        a=a[:l]+chr(r+48)+a[l+1:]
        k=ord(a[0])%3
        if k==0:c_0[0]=1
        elif k==1: c_1[0]=1
        else: c_2[0]=1
        for i in range(1,n):
            cs=(cs*10+ord(a[i])-48)%3
            if cs==0: c_0[i]=c_0[i-1]+1;c_1[i]=c_1[i-1];c_2[i]=c_2[i-1];
            elif cs==1: c_0[i]=c_0[i-1];c_1[i]=c_1[i-1]+1;c_2[i]=c_2[i-1];
            else: c_0[i]=c_0[i-1];c_1[i]=c_1[i-1];c_2[i]=c_2[i-1]+1;
    else:
        l-=1
        r-=1
        no0=c_0[r];no1=c_0[r];no2=c_0[r];
        if l!=0:
            no0-=c_0[l-1]
            no1-=c_1[l-1]
            no2-=c_1[l-1]
        print cc(no0)+cc(no1)+cc(no2)

