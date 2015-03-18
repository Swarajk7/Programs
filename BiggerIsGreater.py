def process(a):
    if(len(a)==1) : return "no answer"
    ind=-1
    for i in range(len(a)-2,-1,-1):
        if a[i]<a[i+1]:
            ind=i
            break
    if ind==-1: return "no answer"
    ans=a[:ind]
    sol=[]
    ansol=[a[ind]]
    for i in range(ind+1,len(a)):
        if a[i]>a[ind]:
            sol.append(a[i])
        ansol.append(a[i])
    sol.sort()
    ansol.sort()
    ansol.remove(sol[0])
    j=''
    for i in ansol: j+=i
    ans=ans+sol[0]+j
    return ans
            
t=int(input())
for i in range(t):
    a=raw_input()
    print process(a)
