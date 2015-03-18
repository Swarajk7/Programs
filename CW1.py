n=int(input())
a=raw_input()
for i in range(n):
    b=raw_input()
    a=a.replace(b,"")
if a=="": print "0"
else: print a
