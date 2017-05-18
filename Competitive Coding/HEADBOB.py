t=int(input())
for i in range(t):
    n=int(input())
    a=raw_input()
    I=False
    Y=False
    if 'I' in a: I=True
    if 'Y' in a: Y=True
    if I and (not Y): print "INDIAN"
    elif Y and (not I): print "NOT INDIAN"
    else: print "NOT SURE"
