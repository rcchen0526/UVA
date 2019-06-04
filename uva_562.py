num=int(input())
while num:
    money, balance=[], []
    SUM=0
    num-=1
    m=int(input())
    data=input().split()
    for item in data:
        money.append(int(item))
        SUM+=int(item)
    half=int(SUM/2)
    for i in range(half+1):
        balance.append(0)
    for i in range(m):
        if half==balance[half]:
            break
        for j in range(half, money[i]-1, -1):
            if half==balance[half]:
                break
            balance[j]=max(balance[j], balance[j-money[i]]+money[i])
    print(SUM-2*balance[half])