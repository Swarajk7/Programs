n=int(input())
a=map(int,raw_input().split())
a.sort()
diff=[0]*(n-1)
if n==1: print "0 0"
else:
    for i in range(0,n-1):
        diff[i]=a[i+1]-a[i]
    x=diff.count(min(diff))
    ans1=1
    ans2=1
    if x==n-1:
        ans1=n*(n-1)/2
        ans2=n*(n-1)/2
    else:
        #print diff
        y=min(diff)
        tc=0
        ans1=0
        for i in diff:
            if i==y:
                tc+=1
            else:
                ans1+=tc*(tc+1)/2
                tc=0
        if tc!=0: ans1+=tc*(tc+1)/2
        nmn=a.count(min(a))
        nmx=a.count(max(a))
        ans2=nmn*nmx
    print ans1,ans2
