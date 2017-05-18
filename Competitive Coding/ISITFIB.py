import math
def is_fibonacci(n):
    phi = 0.5 + 0.5 * math.sqrt(5.0)
    a = phi * n
    return n == 0 or abs(round(a) - a) < 1.0 / n
t=int(input())
for xx in range(t):
    a=int(input())
    if is_fibonacci(a): print "YES"
    else: print "NO"
