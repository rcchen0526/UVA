S=[0]
Case=1
for _ in range(1000):
    S.append(1)
for i in range(2, 1001):
    j=i
    while j<1001:
        S[j]+=i
        j+=i
while True:
    n=int(input())
    if not n:
        break
    p=-1
    for i in range(1000, -1, -1):
        if S[i]==n:
            p=i
            break
    print('Case {}: {}'.format(Case, p))
    Case+=1