num=int(input())
while num:
    num-=1
    n, m=input().split()
    n, m=int(n), int(m)
    v=[]
    dis=[1]
    for i in range(m):
        data=input().split()
        temp=[]
        for item in data:
            temp.append(int(item))
        v.append(temp)

    for i in range(1, n):
        dis.append(1000000000)
    for i in range(n):
        for j in range(m):
            dis[v[j][1]]=min(dis[v[j][1]], dis[v[j][0]]+v[j][2])
    check=True
    for i in range(m):
        if dis[v[i][1]]>dis[v[i][0]]+v[i][2]:
            print('possible')
            check=False
            break
    if check:
        print('not possible')