ar=((),(0,1,2,3,4),(0,2,-1,4,-3),(0,3,-4,-1,2),(0,4,3,-2,-1))
def get(a):
    if a=='1': return 1
    else: return ord(a)-ord('i')+2

dp = [[-1 for x in range(5)] for x in range(10005)] 

def F(req,ind,s):
    cur=1
    if req>4: return False
    if dp[ind][req]!=-1: return dp[ind][req]
    #print req,cur
    while ind!=len(s):
        sign=1
        if cur<0: sign = -1
        cur=sign*ar[abs(cur)][get(s[ind])]
        if cur==req:
            val=F(req+1,ind+1,s)
            if val:
                dp[ind][req]=True
                return True
        ind+=1
    ans = ''
    if cur==req and req==4: ans = True
    else: ans = False
    dp[ind][req]=ans
    return ans
t=int(input())
for t1 in range(1,t+1):
    L,X=map(int,raw_input().split())
    z=raw_input()
    s=''
    for i in range(X): s+=z
    if F(2,0,s): print "YES"
    else: print "NO"

