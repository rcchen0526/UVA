def next_permutation(a):
    for i in reversed(range(len(a) - 1)): 
        if a[i] < a[i + 1]: 
            break
    else:
        return False
    j = next(j for j in reversed(range(i + 1, len(a))) if a[i] < a[j]) 
    a[i], a[j] = a[j], a[i] 
    a[i + 1:] = reversed(a[i + 1:]) 
    return True

num=int(input())
while num:
    num-=1
    temp=input()
    n, h=input().split()
    n, h=int(n), int(h)
    ans=[]
    for _ in range(n-h):
        ans.append('0')
    for _ in range(h):
        ans.append('1')
    while True:
        for item in ans:
            print(item, end='')
        print('')
        if not next_permutation(ans):
            break
    if num:
        print('')