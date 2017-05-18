z="A .-   B -... C -.-. D -.. E .    F ..-. G --.  H .... I ..   J .--- K -.-  L .-.. M --   N -.   O ---  P .--. Q --.- R .-.  S ...  T - U ..-  V ...- W .--  X -..- Y -.-- Z --.."
z=z.split()
d={}
for i in range(0,len(z),2):
    print i,i+1,len(z)
    d[z[i]]=z[i+1]
dd=int(input())
x=[]
for z in range(dd):
    x.append(raw_input())
n=int(input())
z=set()
for i in range(n):
    k=raw_input()
    xx=''
    for i in k:
        xx+=d[i]
    print k,xx
    z.add(xx)
cnt=0
for i in x:
    if i in z:
        cnt+=1
print cnt
