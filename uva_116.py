M=15
N=105
while True:
    graph=[[0] *105 for _ in range(M)]
    path=[[0] *105 for _ in range(M)]
    try:
        m, n = input().split()
        m, n=int(m), int(n)
    except:
        break
    row, col = 0, 0
    while True:
        data=input().split()
        for item in data:
            graph[row][col]=int(item)
            col+=1
            if col==n:
                col=0
                row+=1
        if row==m:
            break
    '''
    for i in range(m):
        for j in range(n):
            print("{} ".format(graph[i][j]), end='')
        print('')
    print('')
    '''
    dp=[[0] *105 for _ in range(M)]
    for col in range(n-1, -1, -1):
        for row in range(m):
            up=(row-1+m)%m
            mid=row
            down=(row+1)%m
            if dp[up][col+1]<dp[mid][col+1]:
                MIN=up
            elif dp[up][col+1]==dp[mid][col+1]:
                MIN=up if up<mid else mid
            else:
                MIN=mid
            if dp[MIN][col+1]>dp[down][col+1]:
                MIN=down
            elif dp[MIN][col+1]==dp[down][col+1]:
                MIN=down if down<MIN else MIN
            path[row][col]=MIN
            dp[row][col]=dp[MIN][col+1]+graph[row][col]
    ans=0
    for i in range(m):
        if dp[i][0]<dp[ans][0]:
            ans=i
    output=dp[ans][0]
    for i in range(n):
        print("{}".format(ans+1), end='')
        if i != n-1:
            print(' ', end='')
        ans=path[ans][i]
    print('')
    print(output)
