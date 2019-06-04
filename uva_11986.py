num=int(input())
for i in range(num):
    N=int(input())
    ans=0
    while N:
        ans+=1
        N=int(N/2)
    print('Case {}: {}'.format(i+1, ans))