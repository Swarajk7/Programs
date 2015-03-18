def primes_sieve(limit):
    limitn = limit+1
    not_prime = [False] * limitn
    primes = []

    for i in range(2, limitn):
        if not_prime[i]:
            continue
        for f in xrange(i*2, limitn, i):
            not_prime[f] = True

        primes.append(i)
    return primes
def pp(p):
    print p
p=primes_sieve(55000)
def z(n):
    j=0
    for i in p:
        if i>n: break
        while n%i==0:
            yield i
            j+=1
            n/=i
    if n!=1:
        yield i
        j+=1
    print "j=",j
t=int(input())
for ii in range(t):
    n=int(input())
    ar=z(n)
    for i in ar:print i
