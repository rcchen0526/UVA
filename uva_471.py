MAX=9876543210
def check(n):
    digit=[0 for _ in range(10)]
    while n:
        if not digit[n%10]:
            digit[n%10]=True
        else:
            return False
        n=int(n/10)
    return True
num=int(input())
while num:
    num-=1
    temp=input()
    N=int(input())
    S2=1
    while S2<MAX:
        S1=S2*N
        if check(S1) and check(S2):
            print('{} / {} = {}'.format(S1, S2, N))
        if S1>MAX:
            break
        S2+=1
    if num:
        print('')