final=-1
def f(n,k,ans):
    print n
    global final
    print final
    if final!=-1: return ans
    if n==0 and ans%k==0:
        final=ans
        return ans
    if n==0: return 81370193901
    else:
        for j in range(n):
            ans=min(n-j,k,ans*10+j)
        return ans
print f(10,10,0)
print final
            
