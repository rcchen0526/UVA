import math
def H(n):
    if n<=0:
        return 0
    ans, i=0, 1
    tmp=int(math.sqrt(n))
    while i<=tmp:
        ans+=int(n/i)
        i+=1
    return 2*ans-tmp*tmp
num=int(input())
while num:
    num-=1
    n=int(input())
    print(H(n))