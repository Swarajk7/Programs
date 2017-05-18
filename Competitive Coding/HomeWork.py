ar=[0]*((10**7)+10)
for i in range(2,len(ar)):
    if ar[i]!=0: continue
    j=i+i
    while j<len(ar):
        ar[j]+=1
        j=j+i
print ar[550]
