import math
def mod(a, n):
    N=1000
    ans=a if n%2 else 1
    while int(n/2):
        n=int(n/2)
        temp=(a*a)%N
        if n%2:
            ans=(ans*temp)%N
        a=temp
    return ans
def first3digit(n, k):
    f=k*math.log10( n)-int(k*math.log10(n))
    return int(pow(10, 2+f))

N=int(input())
for _ in range(N):
    data=input().split()
    data[0], data[1]=int(data[0]), int(data[1])
    last3digit=mod(data[0]%1000, data[1])
    last3digit="%03d"%last3digit
    print("{}...{}".format(first3digit(data[0], data[1]),\
                            last3digit))