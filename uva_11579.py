import math
def area(a, b, c):
    s=(a+b+c)/2
    return s*(s-a)*(s-b)*(s-c)
num=int(input())
for _ in range(num):
    data=input().split()
    N=int(data[0])
    for i in range(N):
        data[i]=float(data[i+1])
    data=data[:-1]
    data.sort()
    ans=0.
    for i in range(N-2):
        if data[i]+data[i+1]<=data[i+2]:
            continue
        temp=area(data[i], data[i+1], data[i+2])
        ans=temp if temp>ans else ans
    ans='%.2f'%math.sqrt(ans)
    print(ans)

