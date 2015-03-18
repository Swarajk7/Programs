import sys
for line in sys.stdin:
    line=line.strip()
    if line=="": continue
    lvl=0
    i=0
    while line[i]=='#': i+=1
    lvl=i
    line=line[i:]
    line = line.split('<')[1]
    line = line.split('>')[0]
    line=line.strip()
    if line[0]=='/': continue
    else:
        line1=line.split()
        if line1[0][-1]=='/':
            line1[0]=line1[0][:len(line1[0])-1]
        print line1[0],lvl,len(line.split("="))-1
