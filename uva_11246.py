num=int(input())
for _ in range(num):
    ans=0
    n, k=input().split()
    n, k=int(n), int(k)
    sign=True
    while n:
        ans+=n if sign else -n
        n=int(n/k)
        sign=False if sign else True
    print(ans)