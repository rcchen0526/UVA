num=int(input())
while True:
    if not num:
        break
    num-=1
    l1 = input()
    l2 = l1[::-1]
    length=len(l1)
    if length==0:
        print('0')
        continue
    lcs=[ [0]*1001 for _ in range(1001)]
    for i in range(1, length+1):
        for j in range(1, length+1):
            if l1[j-1]==l2[i-1]:
                lcs[i][j]=lcs[i-1][j-1]+1
            else:
                lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1])

    print( lcs[length][length])
