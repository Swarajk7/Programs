s="739397"
zz=set()
for i in range(len(s)):
    for j in range(i+1,len(s)):
        z=s[i:j+1]
        if z!='':
            zz.add(int(z))
print len(zz),zz
