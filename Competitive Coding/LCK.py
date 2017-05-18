'''t=int(input())
for i in range(t):
    n=int(input())
    ar=map(int,raw_input().split())
    Q=int(input())
    ans=0
    q=Q
    for i in range(len(ar)):
        if ar[i]>=q:
            ans+=(ar[i]-q)
            q=Q
        else:
            q-=ar[i]
    print ans'''
def isprime(n):
    if num < 2:
        return False
    if num == 2:
        return True
    else:
        for div in range(2,num):
            if num % div == 0:
                return False
        return True
ans=''
t=int(input())
for i in range(t):
    a=raw_input()
    a=map(int,list(a))
    a=sum(a)
    #print a
    if isprime(a): ans=ans+'1'
    else: ans = ans+'0'
print int(ans,2)
