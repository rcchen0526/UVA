x=[0. for _ in range(202)]
y=[0. for _ in range(202)]
Case=1
while True:
    try:
        num=int(input())
    except:
        break
    if not num:
        break
    MAP=[ [0.]*num for _ in range(num)]
    for i in range(num):
        data=input().split()
        x[i]=int(data[0])
        y[i]=int(data[1])
    data=input()
    for i in range(1, num):
        for j in range(i):
            dis=(x[i]-x[j])**2 + (y[i]-y[j])**2 
            MAP[i][j]=MAP[j][i]=dis
    for k in range(2, num):
        for i in range(num):
            for j in range(1, num):
                MAX=max(MAP[i][k], MAP[k][j])
                if MAP[i][j]>MAX:
                    MAP[i][j]=MAX
    print("Scenario #{}".format(Case))
    Case+=1
    print("Frog Distance = %.3f" % (MAP[0][1])**0.5)
    print('')