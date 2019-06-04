num=1
while True:
    l1, l2=[], []
    N1, N2=input().split()
    N1, N2=int(N1), int(N2)
    if not N1 or not N2:
        break
    ll1=input().split()
    ll2=input().split()
    for i in ll1:
        l1.append(i)
    for i in ll2:
        l2.append(i)
    lcs=[ [0]*101 for _ in range(101)]
    for i in range(1, N2+1):
        for j in range(1, N1+1):
            if l1[j-1]==l2[i-1]:
                lcs[i][j]=lcs[i-1][j-1]+1
            else:
                lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1])
    print( "Twin Towers #{}".format(num))
    num+=1
    print( "Number of Tiles : {}".format(lcs[N2][N1]) )
    print( '')
