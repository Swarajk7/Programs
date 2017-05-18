t=int(input())
ar=[]
for i in range(t):
    n=raw_input()
    ar.append(n)
hsh=[0]*26
def rec(ar,ind):
    print ar,ind
    hsh1=[list() for i in range(26)]
    i=0
    cur=0
    val=0
    if hsh[cur]!=0:
        hsh[cur]=val+1
        val+=1
    hsh1[ord(ar[i][ind])-97].append(ar[i])
    i=1
    while i<len(ar):
        if ind<len(ar[i]):
            if ar[i][ind]==ar[cur][ind]:
                hsh1[ord(ar[i][ind])-97].append(ar[i])
            else:
                cur=i
                if hsh[cur]!=0:
                    hsh[cur]=val+1
                    val+=1
                hsh1[ord(ar[i][ind])-97].append(ar[i])
        i+=1
    for i in hsh1:
        if len(i)!=0:
            rec(i,ind+1)

rec(ar,0)
