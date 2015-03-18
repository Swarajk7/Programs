t=int(input())
d={}
for zz in range(t):
    a=raw_input()
    if a not in d.keys():
        d[a]=1
    else: d[a]+=1
for i in sorted(d.keys()):
    print i,d[i]
