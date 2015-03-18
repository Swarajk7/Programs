a=[False]*775150
for i in range(2,len(a)):
    if a[i]: continue
    for j in range(i+i,len(a),i): a[j]=True
z=600851475143
for i in range(len(a),-1,-1):
    if z%i==0 and a[i]==False:
        print i
        break
