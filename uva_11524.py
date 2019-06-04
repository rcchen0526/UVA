import math
num=int(input())
while num:
    num-=1
    r=float(input())
    temp=input().split()
    m1, n1=float(temp[0]), float(temp[1])
    temp=input().split()
    m2, n2=float(temp[0]), float(temp[1])
    temp=input().split()
    m3, n3=float(temp[0]), float(temp[1])
    a, b, c=1., n1*(m2+n2)/(m2*(m1+n1)), m1*(m3+n3)/(n3*(m1+n1))
    k=r*math.sqrt((a+b+c)/(a+b-c)/(a+c-b)/(b+c-a));
    ans='%.4f'% ((a+b+c)*r*k)
    print(ans)