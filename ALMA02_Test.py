N=1000
s=""
for i in range(1,N+1):
    s+=str(i)
t=int(input())
for i in range(t):
    a=int(input())
    print s[a-1]
