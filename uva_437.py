import functools
def comp(x, y):
    if x[0] != y[0]:
        if x[0]<y[0]:
            return -1
        else:
            return 1
    else:
        if x[1]<y[1]:
            return -1
        else:
            return 1

Case=1
while True:
    box=[]
    try:
        num = int(input())
        if not num:
            break
    except:
        break
    for _ in range(num):
        data=input().split()
        for i in range(3):
            data_temp=data.copy()
            data_temp[0]=max(int(data[(i-1+3)%3]), int(data[(i+1)%3]) );
            data_temp[1]=min(int(data[(i-1+3)%3]), int(data[(i+1)%3]) );
            data_temp[2]=int(data[i]);
            box.append(data_temp);

    box=sorted(box, key=functools.cmp_to_key(comp))
    DP=[]
    for i in range(3*num):
        DP.append(0)
    ans=0
    for i in range(len(box)):
        DP[i]=box[i][2]
        for j in range(i+1):
            if box[j][0]<box[i][0] and box[j][1]<box[i][1] and DP[i]<DP[j]+box[i][2]:
                DP[i]=DP[j]+box[i][2]
        ans=max(ans, DP[i])
    print ("Case {}: maximum height = {}".format(Case, ans))
    Case+=1