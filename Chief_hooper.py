n=int(input())
ar=map(int,raw_input().split())
z=sum(ar)
def satisfy(mid):
    init=mid
    for i in ar:
        if i>init: init-=(i-init)
        else: init+=(-i+init)
        if init<0: return False
    return True
def get():
    l=0
    r=z
    ans=z
    while l<=r:
        mid=(l+r)/2
        if satisfy(mid):
            r=mid-1
            ans=mid
        else:
            l=mid+1
    return ans
print get()
