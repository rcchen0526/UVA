while True:
    try:
        input_s=input().split()
    except:
        break
    n, t=int(input_s[0]), int(input_s[1])
    CD=[0 for _ in input_s]
    for i in range(1, t+1):
        CD[i]=int(input_s[i+1])
    dp=[[0]*30 for _ in range(1024)]
    for i in range(1, n+1):
        for j in range(1, t+1):
            dp[i][j]=max(dp[i][j-1], dp[i-CD[j]][j-1]+CD[j]) if CD[j]<=i else dp[i][j-1]
    _n, _t=n, t
    while _n and _t:
        if dp[_n][_t]!=dp[_n][_t-1]:
            _n-=CD[_t]
            print("{} ".format(CD[_t]), end='')
        _t-=1
    print("sum:{}".format(dp[n][t]))