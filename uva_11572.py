def lis(s):
    if not len(s):
        return 0
    pos=[-1 for _ in range(1000001)]
    start, MAX=0, 0
    s.append(s[-1])
    for i in range(len(s)):
        if pos[s[i]]>=start:
            tmp=i-start
            MAX=MAX if MAX>tmp else tmp
            start=pos[s[i]]+1
            pos[s[i]]=i
        else:
            pos[s[i]]=i
    return MAX

case=int(input())
while case:
    case-=1
    n=int(input())
    data=[]
    for _ in range(n):
        data.append(int(input()))
    print(lis(data))