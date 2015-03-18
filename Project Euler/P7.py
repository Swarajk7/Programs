a=[False]*775150
for i in range(2,len(a)):
    if a[i]: continue
    for j in range(i+i,len(a),i): a[j]=True
def z(i):
    return i==False
k=0
for i in range(2,len(a)):
    if a[i]==False: k+=1
    if k==10001:
        print i
        break

