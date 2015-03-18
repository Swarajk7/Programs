a=[False]*2000000
for i in range(2,len(a)):
    if a[i]: continue
    for j in range(i+i,len(a),i): a[j]=True
s=0;
for i in range(2,len(a)):
    if not a[i]: s+=i
print s
