q=[]
MAP=[ [ [0]*32 for _ in range(32) ] for i in range(32)]
L, R, C = None, None, None
def bfs(end_i, end_j, end_k):
    global q, MAP, L, R, C
    while len(q):
        i, j, k, n=q[0][0], q[0][1], q[0][2], q[0][3]
        if i==end_i and j==end_j and k==end_k:
            q=[]
            return n
        else:
            n+=1
            if (i+1)<L and MAP[i+1][j][k]:
                MAP[i+1][j][k]=0
                data=[i+1, j, k, n]
                q.append(data)
            if (i-1)>=0 and MAP[i-1][j][k]:
                MAP[i-1][j][k]=0
                data=[i-1, j, k, n]
                q.append(data)
            if (j+1)<R and MAP[i][j+1][k]:
                MAP[i][j+1][k]=0
                data=[i, j+1, k, n]
                q.append(data)
            if (j-1)>=0 and MAP[i][j-1][k]:
                MAP[i][j-1][k]=0
                data=[i, j-1, k, n]
                q.append(data)
            if (k+1)<C and MAP[i][j][k+1]:
                MAP[i][j][k+1]=0
                data=[i, j, k+1, n]
                q.append(data)
            if (k-1)>=0 and MAP[i][j][k-1]:
                MAP[i][j][k-1]=0
                data=[i, j, k-1, n]
                q.append(data)
        q.pop(0)
    return 0
def char2int(c):
    if c=='E':
        return 1
    if c=='.':
        return 1
    if c=='S':
        return 0
    if c=='#':
        return 0
while True:
    try:
        data=input().split()
        L, R, C = int(data[0]), int(data[1]), int(data[2])
    except:
        break
    if not L and not R and not C:
        break
    for i in range(L):
        for j in range(R):
            data=input()
            for k in range(C):
                MAP[i][j][k]=char2int(data[k])
                if data[k]=='S':
                    start=[i, j, k, 0]
                    q.append(start)
                if data[k]=='E':
                    end_i, end_j, end_k=i, j, k
        temp=input()
    ans=bfs(end_i, end_j, end_k)
    if ans:
        print("Escaped in {} minute(s).".format(ans))
    else:
        print("Trapped!")



