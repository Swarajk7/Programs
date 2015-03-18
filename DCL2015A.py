val=10005
primes=[True]*val
primes[0]=primes[1]=-1
for i in range(2,val):
    if not primes[i]: continue
    j=i+i
    while j<val:
        primes[j]=False
        j+=i
def get(i):
    if i>='a': return ord(i)-ord('a')
    else: return ord(i)-ord('A')+26
t=int(input())
for i in range(t):
    #print i,
    a=raw_input()
    hsh=[0]*52
    for i in a:
        hsh[get(i)]+=1
    z=max(hsh)
    ans=0
    for ii in hsh:
        #print ii,primes[ii],primes[z]
        if primes[z]!=-1 and primes[ii]==primes[z]:
            ans+=ii-(ii/2)
        else: ans+=ii
    print ans

        
