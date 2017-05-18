t=int(input())
for i in range(t):
    e,o=map(int,raw_input().split())
    x=e+o
    k=3*x
    ans=-1
    if k%5==0:
        no=k/5
        ne=x-no
        ans = min (abs(no-o),abs(ne-e))
    print ans
