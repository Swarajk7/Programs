t=int(input())
for i in range(t):
    s=raw_input()
    i=0
    j=len(s)-1
    flag = False
    while i<=j and s[i]==s[j]:
        i+=1
        j-=1
    if i>j:
        flag=True
    else:
        k=s[:i]+s[i+1:]
        k2=s[:j]+s[j+1:]
        if k==k[::-1] or k2==k2[::-1]:
            flag=True
    if flag: print "YES"
    else: print "NO"
