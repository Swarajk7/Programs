def fun(s):
    l=len(s)
    count=0
    for i in range(l):
        for j in range(i+1,l):
            a=s[i:j+1]
            if a==a[::-1]:
                count+=1
    print count
t=int(input())
for i in range(t):
    fun(raw_input())
