a=['C', 'c', 'D', 'd', 'E', 'F', 'f', 'G', 'g', 'A', 'B','S']
d={}
for i in range(len(a)):
    d[a[i]]=i
p=len(a)
mem=[ [0]*p for i in range(p) ]
for i in range(len(a)):
    for j in range(len(a)):
        mem[i][j]=abs(j-i)
        mem[i][j]=min(mem[i][j],p-mem[i][j])
        mem[j][i]=mem[j][i]
#print mem
        
def get(a,b):
    i=d[a]
    j=d[b]
    return mem[i][j]

t=int(input())
for ii in range(t):
    aa=raw_input().split()
    x=get(aa[0],aa[1])
    y=get(aa[1],aa[2])
    if x==4: print "Major"
    else: print "Minor"
