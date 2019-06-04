num=int(input())
temp=input()
while num:
    num-=1
    data=[]
    while True:
        try:
            temp=input()
        except:
            break
        if temp=='':
            break
        data.append(int(temp))
    DP, PATH, ans = [], [], [0]
    for _ in range(len(data)):
        DP.append(0)
        PATH.append(0)

    for i in range(len(data)):
        DP[i]=1
        for j in range(i+1):
            if data[j]< data[i] and DP[i]<DP[j]+1:
                DP[i]=DP[j]+1
                PATH[i]=j
        if DP[i]>ans[0]:
            ans[0]=DP[i]
            last_index=i

    print("Max hits: {}".format(ans[0]) )
    for k in range(ans[0]):
        ans.append(data[last_index])
        last_index=PATH[last_index]
    for i in range(len(ans)-1, 0, -1):
        print(ans[i])
    if num:
        print('')

