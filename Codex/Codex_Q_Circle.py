t=int(input())
pi=3.1415
for ii in range(t):
    n=int(input())
    r=map(float,raw_input().split())
    k=int(input())
    th=map(float,raw_input().split())
    th_max=max(th)
    r_max=max(r)
    ans = (th_max/360)*(r_max*r_max)*pi
    print "%0.2f" % ans
