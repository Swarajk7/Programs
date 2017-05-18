a=int(raw_input())
ans=1
def con(a):
    z=str(a)
    return '8' in z
i=1
while i<=10**9:
    if con(a+i):
        ans=i
        break
    i+=1
print ans
