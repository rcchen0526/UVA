import functools
MAP=[]
alpha=[]
q=[]
def comp(a, b):
    if a[0]!=b[0]:
        if a[0]<b[0]:
            return 1
        else:
            return -1
    else:
        if a[1]<b[1]:
            return -1
        else:
            return 1
def bfs():
    global MAP, alpha, q
    i, j = q[0][0], q[0][1]
    ALPHA = MAP[i][j]
    alpha[ALPHA][0]+=1
    while len(q):
        i, j = q[0][0], q[0][1]
        q.pop(0)
        if MAP[i-1][j]==ALPHA:
            MAP[i-1][j]=-1
            data=[i-1, j]
            q.append(data)

        if MAP[i+1][j]==ALPHA:
            MAP[i+1][j]=-1
            data=[i+1, j]
            q.append(data)

        if MAP[i][j-1]==ALPHA:
            MAP[i][j-1]=-1
            data=[i, j-1]
            q.append(data)

        if MAP[i][j+1]==ALPHA:
            MAP[i][j+1]=-1;
            data=[i, j+1]
            q.append(data)

num=int(input())
for N in range(num):
    alpha=[]
    MAP=[]
    for i in range(26):
        data=[0, i]
        alpha.append(data)
    r, w=input().split()
    r, w = int(r), int(w)
    MAP=[[-1]*(w+2) for _ in range(r+2)]
    for i in range(1, r+1):
        input_s=input()
        for j in range(1, w+1):
            MAP[i][j]=ord(input_s[j-1])-ord('a')
    for i in range(1, r+1):
        for j in range(1, w+1):
            if MAP[i][j]>=0:
                data=[i, j]
                q.append(data)
                bfs()
    alpha=sorted(alpha, key=functools.cmp_to_key(comp))
    print("World #{}".format(N+1))
    for item in alpha:
        if item[0]:
            print("{}: {}".format(chr(ord('a')+item[1]) ,item[0]) )

