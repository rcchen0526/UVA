import functools

def cmp(x, y):
    for i in range(len(x)-1):
        if x[i]<y[i]:
            return -1
        elif x[i]>y[i]:
            return 1
    return 1


def comp(x, y):
    for i in range(len(x)-1):
        if x[i]>=y[i]:
            return False
    return True;

while True:
    try:
        num, dim = input().split()
        num, dim = int(num), int(dim)
    except:
        break
    box=[]
    for N in range(num):
        data=input().split()
        data_temp=[].copy()
        for item in data:
            data_temp.append(int(item))
        data_temp.sort()
        data_temp.append(N+1)
        box.append(data_temp)
    box=sorted(box, key=functools.cmp_to_key(cmp))

    DP, PATH, ans = [], [], [0]
    for _ in range(num):
        DP.append(0)
        PATH.append(0)

    for i in range(num):
        DP[i]=1
        for j in range(i+1):
            if comp(box[j], box[i]) and DP[i]<DP[j]+1:
                DP[i]=DP[j]+1
                PATH[i]=j
        if DP[i]>ans[0]:
            ans[0]=DP[i]
            last_index=i

    print(ans[0])
    for k in range(ans[0]):
        ans.append(box[last_index][dim])
        last_index=PATH[last_index]
    for i in range(len(ans)-1, 0, -1):
        print(ans[i], end='')
        if i!=1:
            print(" ", end='')
    print('')