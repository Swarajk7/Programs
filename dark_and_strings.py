t=int(input())
def isnumeric(a):
    p=ord(a)
    return p>=48 and p<=57
for ii in range(t):
    a=raw_input()
    num=[]
    op=[]
    for i in a:
        if not i.isalpha():
            if isnumeric(i):
                num.append(ord(i)-48)
            else:
                op.append(i)
    op.reverse()
    num.reverse()
    if(len(num)==0):
        print "-1"
        continue
    if(len(num)==1):
        print num.pop()
        continue
    ans=x.pop()
    while len(op)!=0:
        xx=op.pop()
        n1=ans
        n2=num.pop()
        if xx=='+': ans=n1+n2
        elif xx=='-': ans=n1-n2
        elif xx=='*': ans=n1*n2
        elif xx=='/': ans=n1/n2
        else: ans=n1%n2
        #print xx,x
    print ans
        
        
