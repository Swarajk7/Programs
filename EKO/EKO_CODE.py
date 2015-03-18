t=int(input())
for i in range(t):
    n=int(input())
    z=[]
    for i in range(n):
        a,b=map(int,raw_input().split())
        #print a,b
        z.append((a,True))
        z.append((b,False))
    z.sort()
    ans=0
    f_ans=0
    #print z
    for i in z:
        if i[1]: ans+=1
        else: ans-=1
        f_ans=max(ans,f_ans)
    print f_ans
