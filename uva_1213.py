import math
MAXINPUT = 1120
MAXKIND = 14
def prime_list():
    prime=[]
    for i in range(2, MAXINPUT+1):
        check_prime=True
        for j in range(2, int(math.sqrt(i))+1 ):
            if not i%j:
                check_prime=False
                break
        if check_prime:
            prime.append(i)
    return prime

prime=prime_list()
ans=[ [0]*(MAXKIND+1) for _ in range(MAXINPUT+1)]

ans[0][0]=1
for p in prime:
    for n in range(MAXINPUT, p-1, -1):
        for k in range(1, MAXKIND+1):
            ans[n][k]+=ans[n-p][k-1]

while True:
    n, k=input().split()
    n, k=int(n), int(k)
    if not n and not k:
        break
    else:
        print(ans[n][k])