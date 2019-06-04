import math
MAX=1000000
prime=[True for _ in range(MAX)]
is_prime=[]

for i in range(2, MAX):
    if prime[i]:
        j=2*i
        while j<MAX:
            prime[j]=False
            j+=i
        is_prime.append(i)

num=int(input())
for _ in range(num):
    data=input().split()
    data[0], data[1]=int(data[0]), int(data[1])
    ans=0
    i, l, MAX=0, len(is_prime), int(math.sqrt(data[1]))
    while i<l and is_prime[i]<= MAX:
        j=pow(is_prime[i], 2)
        while j<=data[1]:
            if j >= data[0]:
                ans+=1
            j*=is_prime[i]
        i+=1
    print(ans)
