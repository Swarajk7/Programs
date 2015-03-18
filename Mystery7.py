def x(ls,l2):
    a=[0]*26
    for i,j in zip(ls,l2):
        k=0
        while k<len(j):
            a[ord(i[k])-97]=j[k]
            k+=1
    return a

a=x(["key",
"to",
"control",
"nine",
"tails",
"is",
"in",
"your",
"hand"],
    [
        "539",
"86",
"2668765",
"6463",
"82457",
"47",
"46",
"9687",
"4263",
        ])
print map(int,a)
