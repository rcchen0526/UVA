import math
N=int(input())
for Case in range(N):
    ans, c=0., 0.
    n=int(input())
    data_list=input().split()
    for i in range(len(data_list)):
        data=float(data_list[i])
        if data<0:
            ans-=math.exp(c+math.log(-data)-(n-1)*math.log(2))
        elif data>0:
            ans+=math.exp(c+math.log(data)-(n-1)*math.log(2))
        if n-1-i:
            c+=math.log(n-1-i)-math.log(i+1)
        else:
            pass
    if ans:
        ans='%.3f'%ans
    else:
        ans='0.000'
    print("Case #{}: {}".format(Case+1, ans))