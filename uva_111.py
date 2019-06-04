length=int(input())
temp=input().split()
ans = [[0] for _ in range(25)]
for i, item in enumerate(temp):
    ans[int(item)-1]=i+1

while True:
    try:
        test = [[0] for _ in range(25)]
        lcs=[ [0]*25 for _ in range(25)]
        temp=input().split()
        for i, item in enumerate(temp):
            test[int(item)-1]=i+1
        for i in range(1, length+1):
            for j in range(1, length+1):
                if ans[j-1]==test[i-1]:
                    lcs[i][j]=lcs[i-1][j-1]+1
                else:
                    lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1])
        print(lcs[length][length])
    except:
        break