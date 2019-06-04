MAP=[[0]*32 for _ in range(32)]
q=[]
def char2int(c):
    if c=='@':
        return 1
    else:
        return 0
def bfs(i, j):
    global MAP, q
    MAP[i][j]=0
    while len(q):
        i, j = q[0][0], q[0][1]
        if MAP[i-1][j-1]:
           MAP[i-1][j-1]=0;
           data=[i-1, j-1]
           q.append(data)

        if MAP[i-1][j]:
            MAP[i-1][j]=0;
            data=[i-1, j]
            q.append(data)

        if MAP[i-1][j+1]:
            MAP[i-1][j+1]=0;
            data=[i-1, j+1]
            q.append(data)

        if MAP[i][j-1]:
            MAP[i][j-1]=0;
            data=[i, j-1]
            q.append(data)

        if MAP[i][j+1]:
            MAP[i][j+1]=0;
            data=[i, j+1]
            q.append(data)

        if MAP[i+1][j-1]:
            MAP[i+1][j-1]=0;
            data=[i+1, j-1]
            q.append(data)

        if MAP[i+1][j]:
            MAP[i+1][j]=0;
            data=[i+1, j]
            q.append(data)

        if MAP[i+1][j+1]:
            MAP[i+1][j+1]=0;
            data=[i+1, j+1]
            q.append(data)

        q.pop(0)
while True:
    try:
        r, c=input().split()
        r, c, = int(r), int(c)
    except:
        break
    if not r and not c:
        break
    n=0
    MAP=[[0]*102 for _ in range(102)]
    for i in range(1, r+1):
        data=input()
        for j in range(1, c+1):
            MAP[i][j]=char2int(data[j-1])

    for i in range(1, r+1):
        for j in range(1, c+1):
            if MAP[i][j]:
                n+=1
                start=[i, j]
                q.append(start)
                bfs(i, j)
    print(n)