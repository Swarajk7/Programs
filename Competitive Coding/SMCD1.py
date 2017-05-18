t=int(input())
for zz in range(t):
    a=raw_input().split()
    k=''
    for i in a:
        k+=str(len(i))
    print k
