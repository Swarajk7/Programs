t=int(input())
for i in range(t):
    s=raw_input()
    st=set()
    for i in s:
        st.add(i)
    print len(st)
