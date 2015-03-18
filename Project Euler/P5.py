import math
hsh=[0]*21
primes=[2,3,5,7,11,13,17,19]
for i in range(1,21):
    for j in primes:
        if i%j==0:
            k=0
            v=i
            while v%j==0:
                v/=j
                k+=1
            hsh[j]=max(hsh[j],k)
ans=1
for i in primes:
    ans = ans *(i**hsh[i])
print ans
